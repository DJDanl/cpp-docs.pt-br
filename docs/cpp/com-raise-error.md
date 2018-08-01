---
title: com_raise_error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_raise_error
dev_langs:
- C++
helpviewer_keywords:
- _com_raise_error function
ms.assetid: a98226c2-c3fe-44f1-8ff5-85863de11cd6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 54cb2183bccc45446cd68b8d5d6d2753f571009b
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408083"
---
# <a name="comraiseerror"></a>_com_raise_error
**Seção específica da Microsoft**  
  
 Gera uma [com_error](../cpp/com-error-class.md) em resposta a uma falha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __stdcall _com_raise_error(  
   HRESULT hr,  
   IErrorInfo* perrinfo = 0  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hr*  
 Informações de HRESULT.  
  
 *perrinfo*  
 Objeto `IErrorInfo`.  
  
## <a name="remarks"></a>Comentários  
 **com_raise_error**, que é definido em \<comdef >, pode ser substituído por uma versão escrito pelo usuário do mesmo nome e protótipo. Isso poderia ser feito se você quisesse usar `#import`, mas não quisesse usar ao tratamento de exceções do C++. Nesse caso, uma versão de usuário do **com_raise_error** pode decidir fazer um `longjmp` ou exibir uma caixa de mensagem e ser interrompido. No entanto, a versão do usuário não deve retornar, pois o código de suporte do compilador COM não espera que ela retorne.  
  
 Você também pode usar [set_com_error_handler](../cpp/set-com-error-handler.md) para substituir a função de tratamento de erros padrão.  
  
 Por padrão, **com_raise_error** é definido da seguinte maneira:  
  
```cpp  
void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) {  
   throw _com_error(hr, perrinfo);  
}  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<comdef >  
  
 **Lib:** se o **wchar_t is Native Type** opção de compilador está ativada, use comsuppw. lib ou comsuppwd. Se **wchar_t is Native Type** estiver desativado, use comsupp. Para obter mais informações, consulte [/Zc:wchar_t (wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).  
  
## <a name="see-also"></a>Consulte também  
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)   
 [_set_com_error_handler](../cpp/set-com-error-handler.md)