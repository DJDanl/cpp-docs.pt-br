---
title: "GetCodeForDllUnregisterServer | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "GetCodeForDllUnregisterServer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetCodeForDllUnregisterServer"
ms.assetid: 6b152943-8c30-49f4-a55c-d0cba8d27a17
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# GetCodeForDllUnregisterServer
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o código apropriado para cancelar o registro de um servidor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      function GetCodeForDllUnregisterServer(   
   nLineStart,   
   nLineEnd    
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nLineStart`  
 O número de linha de base zero para o início da função.  
  
 `nLineEnd`  
 O número de linha de base zero para o final da função.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o código para cancelar o registro do servidor.  
  
## <a name="remarks"></a>Comentários  
 Chame essa função de membro para recuperar o código apropriado para cancelar o servidor:  
  
|Número de linha|Código|  
|-----------------|----------|  
|0|AFX_MANAGE_STATE(AfxGetStaticModuleState());|  
|1|_AtlModule.UpdateRegistryAppId(False);|  
|2|HRESULT hRes = _AtlModule.UnregisterServer(TRUE);|  
|3|Se (hRes! = S_OK)|  
|4|\treturn hRes;|  
|5|if (!. COleObjectFactory::UpdateRegistryAll(FALSE))|  
|6|\treturn ResultFromScode(SELFREG_E_CLASS);|  
|7|Retorna S_OK;|  
  
 Para cada uma das linhas retornadas, `GetCodeForDllUnregisterServer` adiciona uma guia à esquerda (`\t`) e um par de caracteres "CR-LF" (retorno de carro - alimentação de linha) à direita (`\r\n`).  
  
## <a name="example"></a>Exemplo  
  
```  
// Get the lines numbered 2 and 3 above  
GetCodeForDllUnregisterServer(2, 3)  
  
// returns the following string  
// "\tHRESULT hRes = _AtlModule.UnregisterServer(TRUE);\r\n\tif (hRes != S_OK)\r\n"  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Personalizando assistentes do C++ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C++](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Criando um assistente](../ide/designing-a-wizard.md)   
 [GetCodeForDllRegisterServer](../ide/getcodefordllregisterserver.md)