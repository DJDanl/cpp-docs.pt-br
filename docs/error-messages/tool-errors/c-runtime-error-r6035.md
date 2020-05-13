---
title: Erro em runtime de C R6035
ms.date: 11/04/2016
f1_keywords:
- R6035
helpviewer_keywords:
- R6035
ms.assetid: f8fb50b8-18bf-4258-b96a-b0a9de468d16
ms.openlocfilehash: ff3cd0259df92aa5cdade3f78a240e69f8f6f7de
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377473"
---
# <a name="c-runtime-error-r6035"></a>Erro em runtime de C R6035

Microsoft Visual C++ Runtime Library, Error R6035 - Um módulo neste aplicativo está inicializando o cookie de segurança global do módulo enquanto uma função que depende desse cookie de segurança está ativa.  Ligue para __security_init_cookie mais cedo.

[__security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md) deve ser chamado antes do primeiro uso do cookie de segurança global.

O cookie de segurança global é usado para proteção contra buffer overrun em código compilado com [/GS (Buffer Security Check)](../../build/reference/gs-buffer-security-check.md) e em código que usa tratamento estruturado de exceções. Essencialmente, na entrada em uma função protegida por excesso, o cookie é colocado na pilha e, na saída, o valor na pilha é comparado com o cookie global. Qualquer diferença entre eles indica que ocorreu uma superação de buffer e resulta em encerramento imediato do programa.

Erro R6035 indica que `__security_init_cookie` uma chamada foi feita depois que uma função protegida foi inserida. Se a execução continuasse, um buffer espúrio seria detectado porque o cookie na pilha não corresponderia mais ao cookie global.

Considere o seguinte exemplo de DLL. O ponto de entrada dll está definido como DllEntryPoint através da opção linker [/ENTRY (Entry-Point Symbol).](../../build/reference/entry-entry-point-symbol.md) Isso ignora a inicialização do CRT que normalmente inicializaria o cookie `__security_init_cookie`de segurança global, de modo que a própria DLL deve chamar .

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

Este exemplo gerará erro R6035 porque o DllEntryPoint usa o manuseio estruturado de exceções e, portanto, usa o cookie de segurança para detectar excessos de buffer. Quando o DllInitialize é chamado, o cookie de segurança global já foi colocado na pilha.

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

Neste caso, o DllEntryPoint não está protegido contra excessos de buffer (não tem buffers de strings locais e não usa o manuseio estruturado de exceções); portanto, ele pode `__security_init_cookie`chamar com segurança . Em seguida, ele chama uma função auxiliar que é protegida.

> [!NOTE]
> A mensagem de erro R6035 é gerada apenas pelo CRT de depuração x86, e apenas para o manuseio estruturado de exceções, mas a condição é um erro em todas as plataformas, e para todas as formas de manipulação de exceção, como C++ EH.

## <a name="see-also"></a>Confira também

[Recursos de segurança no MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/06/28/security-features-in-microsoft-visual-c/)
