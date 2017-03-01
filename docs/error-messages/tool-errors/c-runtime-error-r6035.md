---
title: "R6035 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6035
dev_langs:
- C++
helpviewer_keywords:
- R6035
ms.assetid: f8fb50b8-18bf-4258-b96a-b0a9de468d16
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 36f5708780ff2a87c3e70e86a890446fbfde5ebd
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6035"></a>R6035 de erro de tempo de execução do C
Microsoft Visual C++ Runtime Library, erro R6035 - um módulo neste aplicativo está inicializando o cookie de segurança global do módulo, enquanto uma função contar com esse cookie de segurança está ativa.  Chamada security_init_cookie anteriormente.  
  
 [security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md) deve ser chamado antes da primeira utilização do cookie de segurança global.  
  
 O cookie de segurança global é usado para proteção de estouro de buffer no código compilado com [/GS (Buffer Security Check)](../../build/reference/gs-buffer-security-check.md) e no código que usa o tratamento de exceção estruturada. Essencialmente, na entrada para uma função protegida contra estouro, o cookie é colocado na pilha e na saída, o valor na pilha é comparado com o cookie global. Qualquer diferença entre eles indica que uma saturação de buffer ocorreu e resulta em um encerramento imediato do programa.  
  
 Erro R6035 indica que uma chamada para `__security_init_cookie` foi feita depois que uma função protegida foi inserida. Se continuar a execução, uma saturação de buffer falso seria detectada porque o cookie da pilha não corresponderia o cookie global.  
  
 Considere o seguinte exemplo DLL. O ponto de entrada DLL é definido como DllEntryPoint por meio do vinculador [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) opção. Isso ignora a inicialização do CRT que normalmente seria inicializar o cookie de segurança global, para que a própria DLL deve chamar `__security_init_cookie`.  
  
```  
// Wrong way to call __security_init_cookie  
DllEntryPoint(...) {  
   DllInitialize();  
   ...  
   __try {  
      ...  
   } __except()... {  
      ...  
   }  
}  
  
void DllInitialize() {  
   __security_init_cookie();  
}  
```  
  
 Este exemplo irá gerar o erro R6035 porque DllEntryPoint usa o tratamento de exceção estruturada e, portanto, usa o cookie de segurança para detectar saturações de buffer. Quando o que dllinitialize é chamado, o cookie de segurança global já foi colocado na pilha.  
  
 A forma correta é demonstrada neste exemplo:  
  
```  
// Correct way to call __security_init_cookie  
DllEntryPoint(...) {  
   __security_init_cookie();  
   DllEntryHelper();  
}  
  
void DllEntryHelper() {  
   ...  
   __try {  
      ...  
   } __except()... {  
      ...  
   }  
}  
```  
  
 Nesse caso, DllEntryPoint não está protegido contra estouros de buffer (ele tem buffers não local de cadeia de caracteres e não usa o tratamento de exceção estruturada); Portanto, ele pode chamar com segurança `__security_init_cookie`. Depois, ele chama uma função auxiliar que está protegida.  
  
> [!NOTE]
>  Mensagem de erro é R6035 somente gerado pelo x86 depurar CRT, e somente para tratamento de exceções estruturado, mas a condição de erro em todas as plataformas e para todas as formas de exceção trata, como C++ EH.  
  
## <a name="see-also"></a>Consulte também  
 [Análise aprofundada das verificações de segurança do compilador](http://go.microsoft.com/fwlink/?linkid=7260)
