---
title: /Gh (habilitar função de gancho _penter)
ms.date: 11/04/2016
f1_keywords:
- _penter
helpviewer_keywords:
- /Gh compiler option [C++]
- Gh compiler option [C++]
- _penter function
- -Gh compiler option [C++]
ms.assetid: 1510a082-8a0e-486e-a309-6add814b494f
ms.openlocfilehash: 87815b5f0e0450b84acbe3c35b7ef4f31216ec72
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749298"
---
# <a name="gh-enable-_penter-hook-function"></a>/Gh (habilitar função de gancho _penter)

Causa uma chamada `_penter` para a função no início de cada método ou função.

## <a name="syntax"></a>Sintaxe

```
/Gh
```

## <a name="remarks"></a>Comentários

A `_penter` função não faz parte de nenhuma biblioteca e cabe `_penter`a você fornecer uma definição para .

A menos que você `_penter`planeje ligar explicitamente, você não precisa fornecer um protótipo. A função deve aparecer como se tivesse o seguinte protótipo, e deve empurrar o conteúdo de todos os registros na entrada e colocar o conteúdo inalterado na saída:

```cpp
void __declspec(naked) __cdecl _penter( void );
```

Esta declaração não está disponível para projetos de 64 bits.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++.**

1. Clique na página de propriedade Linha de **Comando.**

1. Digite a opção compilador na **caixa Opções adicionais.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="example"></a>Exemplo

O código a seguir, quando compilado `_penter` com **/Gh,** mostra como é chamado duas vezes; uma vez `main` ao entrar na `x`função e uma vez ao entrar na função .

```cpp
// Gh_compiler_option.cpp
// compile with: /Gh
// processor: x86
#include <stdio.h>
void x() {}

int main() {
   x();
}

extern "C" void __declspec(naked) __cdecl _penter( void ) {
   _asm {
      push eax
      push ebx
      push ecx
      push edx
      push ebp
      push edi
      push esi
    }

   printf_s("\nIn a function!");

   _asm {
      pop esi
      pop edi
      pop ebp
      pop edx
      pop ecx
      pop ebx
      pop eax
      ret
    }
}
```

```Output
In a function!
In a function!
```

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
