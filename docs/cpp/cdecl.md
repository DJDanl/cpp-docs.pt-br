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
ms.openlocfilehash: 298485d310ee4039b13781a8b5cd88a489af3b8b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232396"
---
# <a name="cdecl"></a>__cdecl

**Seção específica da Microsoft**

**cdecl** é a convenção de chamada para o C padrão e C++ programas. Porque a pilha é limpa pelo chamador, ele pode fazer `vararg` funções. O **cdecl** convenção de chamada cria executáveis maiores do que [stdcall](../cpp/stdcall.md)porque requer que cada chamada de função para incluir o código de limpeza de pilha. A lista a seguir mostra a implementação dessa convenção de chamada.

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

Para compatibilidade com versões anteriores, **cdecl** e **cdecl** são um sinônimo de **cdecl** , a menos que a opção de compilador [/Za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) for especificado.

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