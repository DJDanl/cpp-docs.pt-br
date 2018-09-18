---
title: cdecl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __cdecl_cpp
dev_langs:
- C++
helpviewer_keywords:
- __cdecl keyword [C++]
ms.assetid: 1ff1d03e-fb4e-4562-8be1-74f1ad6427f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 37804aed04f998c6762cdbbc7012ae10c19a2529
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46066811"
---
# <a name="cdecl"></a>__cdecl

**Seção específica da Microsoft**

**cdecl** é o padrão de convenção de chamada para programas em C e C++. Porque a pilha é limpa pelo chamador, ele pode fazer `vararg` funções. O **cdecl** convenção de chamada cria executáveis maiores do que [stdcall](../cpp/stdcall.md)porque requer que cada chamada de função para incluir o código de limpeza de pilha. A lista a seguir mostra a implementação dessa convenção de chamada.

|Elemento|Implementação|
|-------------|--------------------|
|Ordem de passagem de argumentos|Da direita para a esquerda.|
|Responsabilidade de manutenção de pilha|A função de chamada remove os argumentos da pilha.|
|Convenção de decoração de nome|O caractere de sublinhado (_) é prefixado para nomes, exceto quando \_funções cdecl que usam vínculos do C são exportadas.|
|Convenção de conversão de maiúsculas/minúsculas|Nenhuma conversão de maiúsculas/minúsculas é realizada.|

> [!NOTE]
>  Para obter informações relacionadas, consulte [nomes decorados](../build/reference/decorated-names.md).

Coloque o **cdecl** modificador antes de uma variável ou um nome de função. Como a convenções de chamada e nomenclatura de C são padrão, o único momento em que você deve usar **cdecl** em código x86 é quando você tiver especificado o `/Gv` (vectorcall), `/Gz` (stdcall) ou `/Gr` (fastcall) opção de compilador. O [/Gd](../build/reference/gd-gr-gv-gz-calling-convention.md) forças de opção de compilador o **cdecl** convenção de chamada.

No ARM e x64 processadores **cdecl** é aceito, mas normalmente é ignorado pelo compilador. Por convenção no ARM e x64, os argumentos são passados nos registros quando possível, e os argumentos subsequentes são passados na pilha. No x64 de código, use **cdecl** para substituir o **/Gv** opção do compilador e use a convenção de chamada x64 padrão.

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

## <a name="example"></a>Exemplo

No exemplo a seguir, o compilador é instruído para usar convenções de nomenclatura e chamada em C para a função `system`.

```cpp
// Example of the __cdecl keyword on function
int __cdecl system(const char *);
// Example of the __cdecl keyword on function pointer
typedef BOOL (__cdecl *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);
```

## <a name="see-also"></a>Consulte também

[Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)