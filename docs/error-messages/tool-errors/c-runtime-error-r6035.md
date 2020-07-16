---
title: Erro em runtime de C R6035
ms.date: 11/04/2016
f1_keywords:
- R6035
helpviewer_keywords:
- R6035
ms.assetid: f8fb50b8-18bf-4258-b96a-b0a9de468d16
ms.openlocfilehash: 9b92b1e2e123201d4f50422754b77f62b2ec943b
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404392"
---
# <a name="c-runtime-error-r6035"></a>Erro em runtime de C R6035

Microsoft Visual C++ biblioteca de tempo de execução, erro R6035-um módulo neste aplicativo está inicializando o cookie de segurança global do módulo enquanto uma função que depende desse cookie de segurança está ativa.  Chame __security_init_cookie anteriormente.

[__security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md) deve ser chamado antes do primeiro uso do cookie de segurança global.

O cookie de segurança global é usado para proteção contra estouro de buffer em código compilado com [/GS (verificação de segurança de buffer)](../../build/reference/gs-buffer-security-check.md) e em código que usa manipulação de exceção estruturada. Essencialmente, na entrada para uma função protegida por saturação, o cookie é colocado na pilha e, ao sair, o valor na pilha é comparado com o cookie global. Qualquer diferença entre eles indica que ocorreu uma saturação de buffer e resulta na finalização imediata do programa.

Erro R6035 indica que uma chamada para `__security_init_cookie` foi feita depois que uma função protegida foi inserida. Se a execução fosse continuar, uma saturação de buffer falsa seria detectada porque o cookie na pilha não corresponderia mais ao cookie global.

Considere o exemplo de DLL a seguir. O ponto de entrada da DLL é definido como DllEntryPoint por meio da opção/entry do vinculador [(símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) . Isso ignora a inicialização do CRT que normalmente inicializaria o cookie de segurança global, portanto, a própria DLL deve chamar `__security_init_cookie` .

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

Este exemplo irá gerar o erro R6035 porque o DllEntryPoint usa manipulação de exceção estruturada e, portanto, usa o cookie de segurança para detectar saturações de buffer. Quando o DllInitialize de tempo é chamado, o cookie de segurança global já foi colocado na pilha.

A maneira correta é demonstrada neste exemplo:

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

Nesse caso, DllEntryPoint não é protegido contra estouros de buffer (ele não tem buffers de cadeia de caracteres locais e não usa manipulação de exceção estruturada); Portanto, ele pode chamar com segurança `__security_init_cookie` . Em seguida, ele chama uma função auxiliar que é protegida.

> [!NOTE]
> A mensagem de erro R6035 é gerada apenas pelo CRT Debug do x86 e somente para manipulação de exceção estruturada, mas a condição é um erro em todas as plataformas e para todas as formas de manipulação de exceção, como C++ EH.

## <a name="see-also"></a>Confira também

[Recursos de segurança no MSVC](https://devblogs.microsoft.com/cppblog/security-features-in-microsoft-visual-c/)
