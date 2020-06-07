using ExampleHumidityServer.ResponseModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;

namespace ExampleHumidityServer.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class HumidityController : ControllerBase
    {
        private readonly ILogger<HumidityController> _logger;

        public HumidityController(ILogger<HumidityController> logger)
        {
            _logger = logger;
        }

        [HttpPost]
        public AcceptedResult Post([FromBody] Humidity humidity)
        {
            _logger.LogInformation($"Received {humidity.HumidityPercentage}%");
            return Accepted();
        }
    }
}