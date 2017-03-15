---
title: "GetCodeForDllGetClassObject | Microsoft Docs"
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
  - "GetCodeForDllGetClassObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetCodeForDllGetClassObject"
ms.assetid: 67b61b3b-9784-494f-ba01-17bffa9941ff
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# GetCodeForDllGetClassObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera o código para o objeto de classe DLL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      function GetCodeForDllGetClassObject(   
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
 Uma cadeia de caracteres que contém o código para obter o objeto de classe.  
  
## <a name="remarks"></a>Comentários  
 Chame essa função de membro para recuperar o código para o objeto de classe. Chamar essa função cria uma única cadeia de caracteres concatenando os elementos da matriz especificado.  
  
 A tabela a seguir mostra o código para obter o código para o objeto de classe:  
  
|Número de linha|Código|  
|-----------------|----------|  
|0|AFX_MANAGE_STATE(AfxGetStaticModuleState());|  
|1|Se (S_OK = = _AtlModule.GetClassObject (rclsid, riid, ppv))|  
|2|\treturn S_OK;|  
|3|retornar AfxDllGetClassObject (rclsid, riid, ppv);|  
  
 Para cada uma das linhas retornadas, `GetCodeForDllGetClassObject` adiciona uma guia à esquerda (`\t`) e um par de caracteres "CR-LF" (retorno de carro - alimentação de linha) à direita (`\r\n`).  
  
## <a name="example"></a>Exemplo  
  
```  
// Get the lines numbered 1 and 2 above  
GetCodeForDllGetClassObject(1, 2)  
  
// returns the following string  
// "\tif (S_OK == _AtlModule.GetClassObject(rclsid, riid, ppv))\r\n\t\treturn S_OK;\r\n"  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Personalizando assistentes do C++ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C++](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Criando um assistente](../ide/designing-a-wizard.md)