---
title: /GS (verificação de segurança do buffer)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.BufferSecurityCheck
- VC.Project.VCCLCompilerTool.BufferSecurityCheck
helpviewer_keywords:
- buffers [C++], buffer overruns
- buffer overruns, compiler /GS switch
- GS compiler option [C++]
- /GS compiler option [C++]
- security check compiler option [C++]
- -GS compiler option [C++]
- buffers [C++], avoiding overruns
ms.assetid: 8d8a5ea1-cd5e-42e1-bc36-66e1cd7e731e
ms.openlocfilehash: 92d296e8079a9ecd8d366c46bbdad8b2ee5dc313
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439566"
---
# <a name="gs-buffer-security-check"></a>/GS (verificação de segurança do buffer)

Detecta algumas saturações de buffer que substituem o endereço de retorno de uma função, o endereço do manipulador de exceção ou determinados tipos de parâmetros. A causa de uma saturação de buffer é uma técnica usada por hackers para explorar o código que não impõe restrições de tamanho de buffer.

## <a name="syntax"></a>Sintaxe

```
/GS[-]
```

## <a name="remarks"></a>Comentários

O **/GS** está ativado por padrão. Se você espera que seu aplicativo não tenha nenhuma exposição de segurança, use **/GS-** . Para obter mais informações sobre como suprimir a detecção de estouro de buffer, consulte [safebuffers](../../cpp/safebuffers.md).

## <a name="security-checks"></a>Verificações de segurança

Em funções que o compilador reconhece como sujeito a problemas de saturação de buffer, o compilador aloca espaço na pilha antes do endereço de retorno. Na entrada da função, o espaço alocado é carregado com um *cookie de segurança* que é calculado uma vez no carregamento do módulo. Na saída da função, e durante o desenrolamento do quadro em sistemas operacionais de 64 bits, uma função auxiliar é chamada para garantir que o valor do cookie ainda seja o mesmo. Um valor diferente indica que uma substituição da pilha pode ter ocorrido. Se um valor diferente for detectado, o processo será encerrado.

## <a name="gs-buffers"></a>Buffers GS

Uma verificação de segurança de saturação de buffer é executada em um *buffer GS*. Um buffer GS pode ser um dos seguintes:

- Uma matriz com mais de 4 bytes tem mais de dois elementos e tem um tipo de elemento que não é um tipo de ponteiro.

- Uma estrutura de dados cujo tamanho tem mais de 8 bytes e não contém ponteiros.

- Um buffer alocado usando a função [_alloca](../../c-runtime-library/reference/alloca.md) .

- Qualquer classe ou estrutura que contenha um buffer GS.

Por exemplo, as instruções a seguir declaram buffers GS.

```cpp
char buffer[20];
int buffer[20];
struct { int a; int b; int c; int d; } myStruct;
struct { int a; char buf[20]; };
```

No entanto, as instruções a seguir não declaram buffers GS. As duas primeiras declarações contêm elementos de tipo de ponteiro. A terceira e a quarta instruções declaram matrizes cujo tamanho é muito pequeno. A quinta instrução declara uma estrutura cujo tamanho em uma plataforma x86 não tem mais de 8 bytes.

```cpp
char *pBuf[20];
void *pv[20];
char buf[4];
int buf[2];
struct { int a; int b; };
```

## <a name="initialize-the-security-cookie"></a>Inicializar o cookie de segurança

A opção de compilador **/GS** requer que o cookie de segurança seja inicializado antes que qualquer função que usa o cookie seja executada. O cookie de segurança deve ser inicializado imediatamente na entrada para um EXE ou DLL. Isso é feito automaticamente se você usar os pontos de entrada VCRuntime padrão: mainCRTStartup, wmainCRTStartup, WinMainCRTStartup, wWinMainCRTStartup ou _DllMainCRTStartup. Se você usar um ponto de entrada alternativo, deverá inicializar manualmente o cookie de segurança chamando [__security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md).

## <a name="what-is-protected"></a>O que é protegido

A opção de compilador **/GS** protege os seguintes itens:

- O endereço de retorno de uma chamada de função.

- O endereço de um manipulador de exceção para uma função.

- Parâmetros de função vulneráveis.

Em todas as plataformas, o **/GS** tenta detectar saturações de buffer no endereço de retorno. As saturações de buffer são exploradas mais facilmente em plataformas como x86 e x64, que usam convenções de chamada que armazenam o endereço de retorno de uma chamada de função na pilha.

No x86, se uma função usar um manipulador de exceção, o compilador injetará um cookie de segurança para proteger o endereço do manipulador de exceção. O cookie é verificado durante o desenrolamento do quadro.

**/GS** protege *parâmetros vulneráveis* que são passados para uma função. Um parâmetro vulnerável é um ponteiro, uma C++ referência, uma estrutura C (C++ tipo de Pod) que contém um ponteiro ou um buffer GS.

Um parâmetro vulnerável é alocado antes do cookie e das variáveis locais. Uma saturação de buffer pode substituir esses parâmetros. E o código na função que usa esses parâmetros pode causar um ataque antes que a função seja retornada e a verificação de segurança seja executada. Para minimizar esse perigo, o compilador faz uma cópia dos parâmetros vulneráveis durante a função prólogo e os coloca abaixo da área de armazenamento para quaisquer buffers.

O compilador não faz cópias de parâmetros vulneráveis nas seguintes situações:

- Funções que não contêm um buffer GS.

- As otimizações ([/o opções](o-options-optimize-code.md)) não estão habilitadas.

- Funções que têm uma lista de argumentos variáveis (...).

- Funções que são marcadas com [Naked](../../cpp/naked-cpp.md).

- Funções que contêm código de assembly embutido na primeira instrução.

- Um parâmetro é usado apenas de maneiras que são menos prováveis de serem exploráveis no caso de uma saturação de buffer.

## <a name="what-is-not-protected"></a>O que não está protegido

A opção de compilador **/GS** não protege contra todos os ataques de segurança contra estouro de buffer. Por exemplo, se você tiver um buffer e uma vtable em um objeto, uma saturação de buffer poderá corromper a vtable.

Mesmo que você use **/GS**, sempre tente escrever código seguro que não tenha saturações de buffer.

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no projeto e clique em **Propriedades**.

   Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Na caixa de diálogo **páginas de propriedades** , clique na pasta **C/C++**  .

1. Clique na página de propriedades **geração de código** .

1. Modifique a propriedade de **verificação de segurança do buffer** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BufferSecurityCheck%2A>.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo satura um buffer. Isso faz com que o aplicativo falhe em tempo de execução.

```C
// compile with: /c /W1
#include <cstring>
#include <stdlib.h>
#pragma warning(disable : 4996)   // for strcpy use

// Vulnerable function
void vulnerable(const char *str) {
   char buffer[10];
   strcpy(buffer, str); // overrun buffer !!!

   // use a secure CRT function to help prevent buffer overruns
   // truncate string to fit a 10 byte buffer
   // strncpy_s(buffer, _countof(buffer), str, _TRUNCATE);
}

int main() {
   // declare buffer that is bigger than expected
   char large_buffer[] = "This string is longer than 10 characters!!";
   vulnerable(large_buffer);
}
```

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
