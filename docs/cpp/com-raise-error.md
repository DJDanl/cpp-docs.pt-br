---
title: com_raise_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_raise_error
dev_langs:
- C++
helpviewer_keywords:
- _com_raise_error function
ms.assetid: a98226c2-c3fe-44f1-8ff5-85863de11cd6
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 1f2072a6f3a6f78bc6751e39e0c79d978845fe97
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comraiseerror"></a>_com_raise_error
**Seção específica da Microsoft**  
  
 Gera um [com_error](../cpp/com-error-class.md) em resposta a uma falha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void __stdcall _com_raise_error(  
   HRESULT hr,  
   IErrorInfo* perrinfo = 0  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hr`  
 Informações de `HRESULT`.  
  
 `perrinfo`  
 **IErrorInfo** objeto.  
  
## <a name="remarks"></a>Comentários  
 `_com_raise_error`, que é definido em comdef.h, pode ser substituído por uma versão gravada pelo usuário dos mesmos nome e protótipo. Isso poderia ser feito se você quisesse usar `#import`, mas não quisesse usar ao tratamento de exceções do C++. No caso, uma versão do usuário **com_raise_error** pode optar por fazer uma `longjmp` ou exibir uma caixa de mensagem e parada. No entanto, a versão do usuário não deve retornar, pois o código de suporte do compilador COM não espera que ela retorne.  
  
 Você também pode usar [set_com_error_handler](../cpp/set-com-error-handler.md) para substituir a função de tratamento de erros padrão.  
  
 Por padrão, `_com_raise_error` é definido da seguinte forma:  
  
```  
void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) {  
   throw _com_error(hr, perrinfo);  
}  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** comdef.h  
  
 **Lib:** se o **wchar_t é do tipo nativo** opção de compilador está ativada, use comsuppw.lib ou comsuppwd.lib. Se **wchar_t é do tipo nativo** está desativado, use comsupp.lib. Para obter mais informações, consulte [/Zc:wchar_t (wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).  
  
## <a name="see-also"></a>Consulte também  
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)   
 [_set_com_error_handler](../cpp/set-com-error-handler.md)
