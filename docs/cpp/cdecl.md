---
title: __cdecl
ms.date: 10/09/2018
f1_keywords:
- __cdecl_cpp
- __cdecl
- _cdecl
- cdecl
helpviewer_keywords:
- __cdecl keyword [C++]
ms.assetid: 1ff1d03e-fb4e-4562-8be1-74f1ad6427f1
ms.openlocfilehash: 9c1483d02bcb68d902cae527eb60e3ef9987607c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227576"
---
# <a name="__cdecl"></a>__cdecl

**`__cdecl`** é a Convenção de chamada padrão para programas C e C++. Como a pilha é limpa pelo chamador, ela pode executar `vararg` funções. A **`__cdecl`** Convenção de chamada cria executáveis maiores do que [__stdcall](../cpp/stdcall.md), pois requer cada chamada de função para incluir o código de limpeza da pilha. A lista a seguir mostra a implementação dessa convenção de chamada. O **`__cdecl`** modificador é específico da Microsoft.

|Elemento|Implementação|
|-------------|--------------------|
|Ordem de passagem de argumentos|Da direita para a esquerda.|
|Responsabilidade de manutenção de pilha|A função de chamada remove os argumentos da pilha.|
|Convenção de decoração de nome|O caractere de sublinhado (_) é prefixado para nomes, exceto quando \_ _cdecl funções que usam vínculo de C são exportadas.|
|Convenção de conversão de maiúsculas/minúsculas|Nenhuma conversão de maiúsculas/minúsculas é realizada.|

> [!NOTE]
> Para obter informações relacionadas, consulte [nomes decorados](../build/reference/decorated-names.md).

Coloque o **`__cdecl`** modificador antes de uma variável ou um nome de função. Como as convenções de nomenclatura e chamada C são o padrão, a única vez que você deve usar **`__cdecl`** no código x86 é quando você especificou a `/Gv` opção de compilador (vectorcall), `/Gz` (stdcall) ou `/Gr` (fastcall). A opção de compilador [/gd](../build/reference/gd-gr-gv-gz-calling-convention.md) força a **`__cdecl`** Convenção de chamada.

Em processadores ARM e x64, **`__cdecl`** é aceito, mas normalmente ignorado pelo compilador. Por convenção no ARM e x64, os argumentos são passados nos registros quando possível, e os argumentos subsequentes são passados na pilha. No código x64, use **`__cdecl`** para substituir a opção de compilador **/GV** e use a Convenção de chamada x64 padrão.

Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição. Dada esta definição de classe:

```cpp
struct CMyClass {
   void __cdecl mymethod();
};
```

isto:

```cpp
void CMyClass::mymethod() { return; }
```

equivale a isto:

```cpp
void __cdecl CMyClass::mymethod() { return; }
```

Para compatibilidade com versões anteriores, **cdecl** e **_cdecl** são um sinônimo para **`__cdecl`** , a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

No exemplo a seguir, o compilador é instruído para usar convenções de nomenclatura e chamada em C para a função `system`.

```cpp
// Example of the __cdecl keyword on function
int __cdecl system(const char *);
// Example of the __cdecl keyword on function pointer
typedef BOOL (__cdecl *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);
```

## <a name="see-also"></a>Confira também

[Passagem de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
