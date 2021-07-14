//
//  SwaggerComponent.hpp
//  crud
//
//  Created by Leonid on 7/31/18.
//  Copyright © 2018 oatpp. All rights reserved.
//

#ifndef SwaggerComponent_hpp
#define SwaggerComponent_hpp

#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/core/macro/component.hpp"
#include <oatpp-swagger/Generator.hpp>

/**
 *  Swagger ui is served at
 *  http://host:port/swagger/ui
 */
class SwaggerComponent {
public:

	/**
	 *  General API docs info
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {

		oatpp::swagger::DocumentInfo::Builder builder;

		builder
			.setTitle("OAT++ starter API with Swagger UI")
			.setDescription("C++/OAT++ REST API with Swagger docs")
			.setVersion("1.0")
			.setContactName("Claudio Barca")
			.setContactUrl("https://oatpp.io/")

			.setLicenseName("Apache License, Version 2.0")
			.setLicenseUrl("http://www.apache.org/licenses/LICENSE-2.0")

			.addServer("http://localhost:8000", "server on localhost");


		// .addSecurityScheme("basic_auth", oatpp::swagger::DocumentInfo::SecuritySchemeBuilder::DefaultBasicAuthorizationSecurityScheme());

		return builder.build();

		}());



	/**
	 *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
		// Make sure to specify correct full path to oatpp-swagger/res folder !!!
		return oatpp::swagger::Resources::streamResources(OATPP_SWAGGER_RES_PATH);
		}());

	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Generator::Config>, generatorConfig)([] {
		auto config = std::make_shared<oatpp::swagger::Generator::Config>();
		config->enableInterpretations = { "test" };
		return config;
		}());

};

#endif /* SwaggerComponent_hpp */