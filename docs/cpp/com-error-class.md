---
title: classe com_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error
dev_langs:
- C++
helpviewer_keywords:
- _com_error class
ms.assetid: 70dafa69-b1fb-4a5c-9249-e857e0793d42
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 670be1988adb3ef5afa9113b9988ceafb249801f
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comerror-class"></a>Classe _com_error
**Seção específica da Microsoft**  
  
 Um objeto `_com_error` representa uma condição de exceção detectada pelas funções de wrapper para tratamento de erros nos arquivos de cabeçalho gerados a partir da biblioteca de tipos ou por uma das classes de suporte COM. A classe `_com_error` encapsula o código de erro de `HRESULT` e qualquer objeto `IErrorInfo Interface` associado.  
  
### <a name="construction"></a>Construção  
  
|||  
|-|-|  
|[com_error](../cpp/com-error-com-error.md)|Constrói um objeto `_com_error`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](../cpp/com-error-operator-equal.md)|Atribui um objeto `_com_error` existente a outro.|  
  
### <a name="extractor-functions"></a>Funções de extrator  
  
|||  
|-|-|  
|[Erro](../cpp/com-error-error.md)|Recupera o `HRESULT` passado para o construtor.|  
|[ErrorInfo](../cpp/com-error-errorinfo.md)|Recupera o objeto `IErrorInfo` passado para o construtor.|  
|[WCode](../cpp/com-error-wcode.md)|Recupera o código de erro de 16 bits mapeado para o `HRESULT` encapsulado.|  
  
### <a name="ierrorinfo-functions"></a>Funções IErrorInfo  
  
|||  
|-|-|  
|[Descrição](../cpp/com-error-description.md)|Chama a função `IErrorInfo::GetDescription`.|  
|[HelpContext](../cpp/com-error-helpcontext.md)|Chama a função `IErrorInfo::GetHelpContext`.|  
|[Arquivo de ajuda](../cpp/com-error-helpfile.md)|Chama a função `IErrorInfo::GetHelpFile`.|  
|[Source](../cpp/com-error-source.md)|Chama a função `IErrorInfo::GetSource`.|  
|[GUID](../cpp/com-error-guid.md)|Chama a função `IErrorInfo::GetGUID`.|  
  
### <a name="format-message-extractor"></a>Extrator de mensagem de formato  
  
|||  
|-|-|  
|[Mensagem de erro](../cpp/com-error-errormessage.md)|Recupera a mensagem de cadeia de caracteres para o HRESULT armazenado no objeto `_com_error`.|  
  
### <a name="exepinfowcode-to-hresult-mappers"></a>Mapeadores de ExepInfo.wCode para HRESULT  
  
|||  
|-|-|  
|[HRESULTToWCode](../cpp/com-error-hresulttowcode.md)|Mapas de 32 bits `HRESULT` para 16 bits `wCode`.|  
|[WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)|Mapeia um `wCode` de 16 bits para um `HRESULT` de 32 bits.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** comdef.h  
  
 `Lib:`comsuppw.lib ou comsuppwd.lib (consulte [/ZC: (wchar_t é do tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)  
  
## <a name="see-also"></a>Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)   
 [Interface IErrorInfo](http://msdn.microsoft.com/en-us/4dda6909-2d9a-4727-ae0c-b5f90dcfa447)
