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
ms.openlocfilehash: b4a86c49880b0c40d402c7cec863f79e24bc4dc1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371561"
---
# <a name="__cdecl"></a>__cdecl

**__cdecl** é a convenção de chamada padrão para programas C e C++. Como a pilha é limpa pelo chamador, ela pode fazer `vararg` funções. A convenção de chamada **__cdecl** cria executáveis maiores do que [__stdcall,](../cpp/stdcall.md)porque requer que cada chamada de função inclua o código de limpeza da pilha. A lista a seguir mostra a implementação dessa convenção de chamada. O **modificador __cdecl** é específico da Microsoft.

|Elemento|Implementação|
|-------------|--------------------|
|Ordem de passagem de argumentos|Da direita para a esquerda.|
|Responsabilidade de manutenção de pilha|A função de chamada remove os argumentos da pilha.|
|Convenção de decoração de nome|O caractere Sublinhado (_) é \_prefixado para nomes, exceto quando _cdecl funções que usam linkagem C são exportadas.|
|Convenção de conversão de maiúsculas/minúsculas|Nenhuma conversão de maiúsculas/minúsculas é realizada.|

> [!NOTE]
> Para obter informações [relacionadas,](../build/reference/decorated-names.md)consulte Nomes Decorados .

Coloque o **modificador de __cdecl** antes de uma variável ou um nome de função. Como as convenções de nomeação e chamada C são o padrão, a única vez `/Gv` que você `/Gz` deve usar **__cdecl** no código x86 é quando você especificou a opção (vetorchamada), (stdcall) ou `/Gr` (fastcall) compilador. A [opção /Gd](../build/reference/gd-gr-gv-gz-calling-convention.md) compilador força a **convenção de chamada __cdecl.**

Nos processadores ARM e x64, **__cdecl** é aceita, mas normalmente ignorada pelo compilador. Por convenção no ARM e x64, os argumentos são passados nos registros quando possível, e os argumentos subsequentes são passados na pilha. No código x64, use **__cdecl** para substituir a opção de compilador **/Gv** e usar a convenção de chamada padrão x64.

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

Para compatibilidade com as versões anteriores, **cdecl** e **_cdecl** são um sinônimo de **__cdecl** a menos que a opção de compilação [ \(/Za Disable extensões de idioma seja](../build/reference/za-ze-disable-language-extensions.md) especificada.

## <a name="example"></a>Exemplo

No exemplo a seguir, o compilador é instruído para usar convenções de nomenclatura e chamada em C para a função `system`.

```cpp
// Example of the __cdecl keyword on function
int __cdecl system(const char *);
// Example of the __cdecl keyword on function pointer
typedef BOOL (__cdecl *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);
```

## <a name="see-also"></a>Confira também

[Passagem de argumento e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
