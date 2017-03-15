---
title: "Classe _com_error | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_com_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe _com_error"
ms.assetid: 70dafa69-b1fb-4a5c-9249-e857e0793d42
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe _com_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Um objeto `_com_error` representa uma condição de exceção detectada pelas funções de wrapper para tratamento de erros nos arquivos de cabeçalho gerados a partir da biblioteca de tipos ou por uma das classes de suporte COM.  A classe `_com_error` encapsula o código de erro de `HRESULT` e qualquer objeto `IErrorInfo Interface` associado.  
  
### Construção  
  
|||  
|-|-|  
|[\_com\_error](../cpp/com-error-com-error.md)|Constrói um objeto `_com_error`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../cpp/com-error-operator-equal.md)|Atribui um objeto `_com_error` existente a outro.|  
  
### Funções de extrator  
  
|||  
|-|-|  
|[Erro](../Topic/_com_error::Error.md)|Recupera o `HRESULT` passado para o construtor.|  
|[ErrorInfo](../cpp/com-error-errorinfo.md)|Recupera o objeto `IErrorInfo` passado para o construtor.|  
|[WCode](../cpp/com-error-wcode.md)|Recupera o código de erro de 16 bits mapeado para o `HRESULT` encapsulado.|  
  
### Funções IErrorInfo  
  
|||  
|-|-|  
|[Descrição](../cpp/com-error-description.md)|Chama a função `IErrorInfo::GetDescription`.|  
|[HelpContext](../cpp/com-error-helpcontext.md)|Chama a função `IErrorInfo::GetHelpContext`.|  
|[HelpFile](../Topic/_com_error::HelpFile.md)|Chama a função `IErrorInfo::GetHelpFile`.|  
|[Origem](../cpp/com-error-source.md)|Chama a função `IErrorInfo::GetSource`.|  
|[GUID](../cpp/com-error-guid.md)|Chama a função `IErrorInfo::GetGUID`.|  
  
### Extrator de mensagem de formato  
  
|||  
|-|-|  
|[ErrorMessage](../cpp/com-error-errormessage.md)|Recupera a mensagem de cadeia de caracteres para o HRESULT armazenado no objeto `_com_error`.|  
  
### Mapeadores de ExepInfo.wCode para HRESULT  
  
|||  
|-|-|  
|[HRESULTToWCode](../cpp/com-error-hresulttowcode.md)|Mapeia um `HRESULT` de 32 bits para um `wCode` de 16 bits.|  
|[WCodeToHRESULT](../Topic/_com_error::WCodeToHRESULT.md)|Mapeia um `wCode` de 16 bits para um `HRESULT` de 32 bits.|  
  
## FIM de Específico da Microsoft  
  
## Requisitos  
 `Header:` comdef.h  
  
 `Lib:` comsuppw.lib ou comsuppwd.lib \(consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações\)  
  
## Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)   
 [IErrorInfo Interface](http://msdn.microsoft.com/pt-br/4dda6909-2d9a-4727-ae0c-b5f90dcfa447)