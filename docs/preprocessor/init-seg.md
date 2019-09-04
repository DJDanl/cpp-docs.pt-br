---
title: Pragma init_seg
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.init_seg
- init_seg_CPP
helpviewer_keywords:
- pragmas, init_seg
- init_seg pragma
- data segment initializing [C++]
ms.assetid: 40a5898a-5c85-4aa9-8d73-3d967eb13610
ms.openlocfilehash: 5e57ea0eedfc1df6e196391c5edd3acfbad0a7c7
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221009"
---
# <a name="init_seg-pragma"></a>Pragma init_seg

**C++Determinados**

Especifica uma palavra-chave ou uma seção de código que afeta a ordem na qual o código de inicialização é executado.

## <a name="syntax"></a>Sintaxe

> **#pragma init_seg (** {**usuário** de**biblioteca** | de **compilador** | | "*nome da seção*" [ **,** *Func-Name* ]} **)**

## <a name="remarks"></a>Comentários

Os termos *segmento* e *seção* têm o mesmo significado neste artigo.

Como o código às vezes é necessário para inicializar objetos estáticos globais, você deve especificar quando construir os objetos. Em particular, é importante usar o pragma **init_seg** em bibliotecas de vínculo dinâmico (DLLs) ou em bibliotecas que exigem inicialização.

As opções para o pragma **init_seg** são:

**Compiler**\
Reservado para a inicialização da biblioteca em tempo de execução do Microsoft C. Os objetos nesse grupo são construídos primeiro.

**lib**\
Disponível para as inicializações de fornecedores de bibliotecas de classes de terceiros. Os objetos nesse grupo são construídos após aqueles marcados como **compilador**, mas antes de qualquer outro.

**usuário**\
Disponível para qualquer usuário. Os objetos nesse grupo são construídos por último.

*nome da seção*\
Permite a especificação explícita da seção de inicialização. Os objetos em uma seção especificada *pelo usuário-nome* não são construídos implicitamente. No entanto, seus endereços são colocados na seção chamada por *nome de seção*.

O *nome da seção* que você atribuir conterá ponteiros para funções auxiliares que construirão os objetos globais declarados após o pragma nesse módulo.

Para obter uma lista de nomes que você não deve usar ao criar uma seção, consulte [/Section](../build/reference/section-specify-section-attributes.md).

*Func-Name*\
Especifique uma função a ser chamada no lugar de `atexit` quando o programa é encerrado. Essa função auxiliar também chama [atexit](../c-runtime-library/reference/atexit.md) com um ponteiro para o destruidor para o objeto global. Se você especificar um identificador de função no pragma do formulário,

```cpp
int __cdecl myexit (void (__cdecl *pf)(void))
```

a função será chamada em vez de `atexit` da biblioteca em tempo de execução C. Ele permite que você crie uma lista dos destruidores a serem chamados quando estiver pronto para destruir os objetos.

Se você precisar adiar a inicialização (por exemplo, em uma DLL), opte por especificar explicitamente o nome da seção. Seu código deve então chamar os construtores para cada objeto estático.

Não há aspas em torno do identificador para a substituição de `atexit`.

Seus objetos ainda serão colocados nas seções definidas por outros `XXX_seg` pragmas.

Os objetos declarados no módulo não são inicializados automaticamente pelo tempo de execução C. Seu código deve fazer a inicialização.

Por padrão, as seções `init_seg` são somente leitura. Se o nome da seção `.CRT`for, o compilador alterará silenciosamente o atributo para somente leitura, mesmo que ele esteja marcado como leitura, gravação.

Você não pode especificar **init_seg** mais de uma vez em uma unidade de tradução.

Mesmo que o objeto não tenha um construtor definido pelo usuário, um explicitamente definido no código, o compilador poderá gerar um para você. Por exemplo, ele pode criar um para associar ponteiros de tabela v. Quando necessário, seu código chama o Construtor gerado pelo compilador.

## <a name="example"></a>Exemplo

```cpp
// pragma_directive_init_seg.cpp
#include <stdio.h>
#pragma warning(disable : 4075)

typedef void (__cdecl *PF)(void);
int cxpf = 0;   // number of destructors we need to call
PF pfx[200];    // pointers to destructors.

int myexit (PF pf) {
   pfx[cxpf++] = pf;
   return 0;
}

struct A {
   A() { puts("A()"); }
   ~A() { puts("~A()"); }
};

// ctor & dtor called by CRT startup code
// because this is before the pragma init_seg
A aaaa;

// The order here is important.
// Section names must be 8 characters or less.
// The sections with the same name before the $
// are merged into one section. The order that
// they are merged is determined by sorting
// the characters after the $.
// InitSegStart and InitSegEnd are used to set
// boundaries so we can find the real functions
// that we need to call for initialization.

#pragma section(".mine$a", read)
__declspec(allocate(".mine$a")) const PF InitSegStart = (PF)1;

#pragma section(".mine$z",read)
__declspec(allocate(".mine$z")) const PF InitSegEnd = (PF)1;

// The comparison for 0 is important.
// For now, each section is 256 bytes. When they
// are merged, they are padded with zeros. You
// can't depend on the section being 256 bytes, but
// you can depend on it being padded with zeros.

void InitializeObjects () {
   const PF *x = &InitSegStart;
   for (++x ; x < &InitSegEnd ; ++x)
      if (*x) (*x)();
}

void DestroyObjects () {
   while (cxpf>0) {
      --cxpf;
      (pfx[cxpf])();
   }
}

// by default, goes into a read only section
#pragma init_seg(".mine$m", myexit)

A bbbb;
A cccc;

int main () {
   InitializeObjects();
   DestroyObjects();
}
```

```Output
A()
A()
A()
~A()
~A()
~A()
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
