---
title: Erro em tempo de execução de C R6035
ms.date: 11/04/2016
f1_keywords:
- R6035
helpviewer_keywords:
- R6035
ms.assetid: f8fb50b8-18bf-4258-b96a-b0a9de468d16
ms.openlocfilehash: cbade3ce8686c8c293b8d40a73c546805e42215d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399974"
---
# <a name="c-runtime-error-r6035"></a>Erro em tempo de execução de C R6035

Microsoft Visual C++ Runtime Library, erro R6035 - um módulo neste aplicativo está inicializando o cookie de segurança global do módulo, enquanto uma função de terceira parte confiável no cookie de segurança que está ativa.  Chamada security_init_cookie anteriormente.

[security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md) deve ser chamado antes do primeiro uso do cookie de segurança global.

O cookie de segurança global é usado para proteção de estouro de buffer no código compilado com [/GS (Buffer Security Check)](../../build/reference/gs-buffer-security-check.md) e no código que usa o tratamento de exceções estruturado. Essencialmente, na entrada para uma função protegida contra estouro, o cookie é colocado na pilha e na saída, o valor na pilha é comparado com o cookie global. Qualquer diferença entre eles indica que um estouro de buffer tiver ocorrido e resulta em um encerramento imediato do programa.

Erro em R6035 indica que uma chamada para `__security_init_cookie` foi feita depois que uma função protegida foi inserida. Se a execução continue, um estouro de buffer artificiais seria detectado porque o cookie na pilha não corresponderia o cookie global.

Considere o seguinte exemplo DLL. O ponto de entrada DLL é definido para DllEntryPoint por meio de vinculador [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) opção. Isso ignora a inicialização do CRT que normalmente seria inicializar o cookie de segurança global, portanto, a própria DLL deve chamar `__security_init_cookie`.

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

Este exemplo irá gerar o erro R6035 porque DllEntryPoint usa o tratamento de exceções estruturado e, portanto, usa o cookie de segurança para detectar saturações de buffer. No momento que dllinitialize é chamado, o cookie de segurança global já foi colocado na pilha.

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

Nesse caso, DllEntryPoint não está protegido contra estouros de buffer (ele tem buffers nenhuma cadeia de caracteres local e não usar o tratamento de exceções estruturado); Portanto, ele pode chamar com segurança `__security_init_cookie`. Em seguida, ele chama uma função auxiliar que é protegida.

> [!NOTE]
>  Mensagem de erro é R6035 somente gerados por x86 de depuração CRT e apenas para tratamento de exceções estruturado, mas a condição é um erro em todas as plataformas e para todos os formulários de exceção tratamento, como C++ EH.

## <a name="see-also"></a>Consulte também

[Recursos de segurança no MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/06/28/security-features-in-microsoft-visual-c/)