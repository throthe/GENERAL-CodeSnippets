using HttpClientFactorySample.GitHub;
using HttpClientFactorySample.Handlers;
using HttpClientFactorySample.Services;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Polly;
using System;
using System.Net.Http;

namespace HttpClientFactorySample
{
    public class Startup6
    {
        public Startup6(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public IConfiguration Configuration { get; }
        #region snippet1
        public void ConfigureServices(IServiceCollection services)
        {            
            services.AddHttpClient("configured-inner-handler")
                .ConfigurePrimaryHttpMessageHandler(() =>
                {
                    return new HttpClientHandler()
                    {
                        AllowAutoRedirect = false,
                        UseDefaultCredentials = true
                    };
                });

            // Remaining code deleted for brevity.
            #endregion

            services.AddControllers();
            services.AddRazorPages();
        }
        
        // This method gets called by the runtime. Use this method to configure 
        // the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }
            else
            {
                app.UseExceptionHandler("/Error");
            }

            app.UseRouting();
            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllerRoute(
                    name: "default",
                    pattern: "{controller=Home}/{action=Index}/{id?}");
                endpoints.MapRazorPages();
            });
        }
    }
}
