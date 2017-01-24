---
title: "_com_raise_error | Microsoft Docs"
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
  - "_com_raise_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _com_raise_error"
ms.assetid: a98226c2-c3fe-44f1-8ff5-85863de11cd6
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_raise_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Lança um [\_com\_error](../cpp/com-error-class.md) em resposta a uma falha.  
  
## Sintaxe  
  
```  
  
      void __stdcall _com_raise_error(  
   HRESULT hr,  
   IErrorInfo* perrinfo = 0  
);  
```  
  
#### Parâmetros  
 `hr`  
 Informações de `HRESULT`.  
  
 `perrinfo`  
 Objeto **IErrorInfo**.  
  
## Comentários  
 `_com_raise_error`, que é definido em comdef.h, pode ser substituído por uma versão gravada pelo usuário dos mesmos nome e protótipo.  Isso poderia ser feito se você quisesse usar `#import`, mas não quisesse usar ao tratamento de exceções do C\+\+.  Nesse caso, uma versão do usuário de **\_com\_raise\_error** pode decidir fazer um `longjmp` ou exibir uma caixa de mensagem e parar.  No entanto, a versão do usuário não deve retornar, pois o código de suporte do compilador COM não espera que ela retorne.  
  
 Você também pode usar [\_set\_com\_error\_handler](../cpp/set-com-error-handler.md) para substituir a função padrão de tratamento de erros.  
  
 Por padrão, `_com_raise_error` é definido da seguinte forma:  
  
```  
void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) {  
   throw _com_error(hr, perrinfo);  
}  
```  
  
## FIM de Específico da Microsoft  
  
## Requisitos  
 **Header:** comdef.h  
  
 **Bib:** se a opção do compilador “wchar\_t is Native Type” está ativada, use comsuppw.lib ou comsuppwd.lib.  Se “wchar\_t is Native Type” estiver desativado, use comsupp.lib.  Para obter mais informações, consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).  
  
## Consulte também  
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)   
 [\_set\_com\_error\_handler](../cpp/set-com-error-handler.md)