---
title: /GS (verificação de segurança do buffer)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.BufferSecurityCheck
- VC.Project.VCCLCompilerTool.BufferSecurityCheck
- /GS
helpviewer_keywords:
- buffers [C++], buffer overruns
- buffer overruns, compiler /GS switch
- GS compiler option [C++]
- /GS compiler option [C++]
- security check compiler option [C++]
- -GS compiler option [C++]
- buffers [C++], avoiding overruns
ms.assetid: 8d8a5ea1-cd5e-42e1-bc36-66e1cd7e731e
ms.openlocfilehash: 6681ff09b846011af1b500f88a535c208d0bc1c1
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417561"
---
# <a name="gs-buffer-security-check"></a>/GS (verificação de segurança do buffer)

Detecta alguns estouros de buffer que substituem o endereço de retorno da função, o endereço do manipulador de exceção ou determinados tipos de parâmetros. Causar um estouro de buffer é uma técnica usada por hackers para explorar o código que não impõe restrições de tamanho do buffer.

## <a name="syntax"></a>Sintaxe

```
/GS[-]
```

## <a name="remarks"></a>Comentários

**/GS** é ativado por padrão. Se você espera que seu aplicativo não tenha nenhuma exposição de segurança, use **/GS-**. Para obter mais informações sobre como suprimir a detecção de estouro de buffer, consulte [safebuffers](../../cpp/safebuffers.md).

## <a name="security-checks"></a>Verificações de segurança

Em funções que o compilador reconhece como sujeitos a problemas de estouro de buffer, o compilador aloca espaço na pilha antes do endereço de retorno. Entrada da função, o espaço alocado é carregado com um *cookie de segurança* que é calculada uma vez no carregamento do módulo. Na saída da função e durante o desenrolamento de quadro em sistemas operacionais de 64 bits, uma função auxiliar é chamada para certificar-se de que o valor do cookie ainda é o mesmo. Um valor diferente indica que uma substituição da pilha pode ter ocorrido. Se um valor diferente for detectado, o processo será encerrado.

## <a name="gs-buffers"></a>Buffers de GS

Uma verificação de segurança de estouro de buffer é executada em um *buffer GS*. Um buffer de GS pode ser um destes procedimentos:

- Uma matriz que é maior que 4 bytes, tem mais de dois elementos e tem um tipo de elemento que não é um tipo de ponteiro.

- Uma estrutura de dados cujo tamanho é maior que 8 bytes e não contém nenhum ponteiro.

- Um buffer alocado usando o [alloca](../../c-runtime-library/reference/alloca.md) função.

- Qualquer classe ou estrutura que contém um buffer de GS.

Por exemplo, as seguintes instruções declaram buffers GS.

```cpp
char buffer[20];
int buffer[20];
struct { int a; int b; int c; int d; } myStruct;
struct { int a; char buf[20]; };
```

No entanto, as instruções a seguir não declaram os buffers de GS. As primeiras duas declarações contêm elementos do tipo de ponteiro. As instruções de terceira e quarta declaram matrizes cujo tamanho é muito pequeno. A quinta instrução declara uma estrutura cujo tamanho em uma plataforma não é mais do que 8 bytes de x86.

```cpp
char *pBuf[20];
void *pv[20];
char buf[4];
int buf[2];
struct { int a; int b; };
```

## <a name="initialize-the-security-cookie"></a>Inicializar o Cookie de segurança

O **/GS** opção de compilador requer que o cookie de segurança seja inicializada antes de qualquer função que usa o cookie é executada. O cookie de segurança deve ser inicializado imediatamente na entrada para um arquivo EXE ou DLL. Isso é feito automaticamente se você usar os pontos de entrada do VCRuntime padrão: mainCRTStartup, wmainCRTStartup, WinMainCRTStartup, wWinMainCRTStartup, ou dllmaincrtstartup. Se você usar um ponto de entrada alternativo, você deve inicializar o cookie de segurança manualmente, chamando [security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md).

## <a name="what-is-protected"></a>O que é protegido

O **/GS** opção de compilador protege os seguintes itens:

- O endereço de retorno de uma chamada de função.

- O endereço de um manipulador de exceção para uma função.

- Parâmetros de função vulnerável.

Em todas as plataformas, **/GS** tenta detectar saturações de buffer para o endereço de retorno. Saturações de buffer são exploradas mais facilmente em plataformas como x86 e x64, que usam as convenções de chamada que armazenam o endereço de retorno de uma chamada de função na pilha.

Em x86, se uma função usa um manipulador de exceção, o compilador injeta um cookie de segurança para proteger o endereço do manipulador de exceção. O cookie é verificado durante o desenrolamento de quadro.

**/GS** protege *vulneráveis parâmetros* que são passados para uma função. Um parâmetro vulnerável for um ponteiro, uma referência de C++, uma C-estrutura (tipo de POD do C++) que contém um ponteiro ou um buffer de GS.

Um parâmetro vulnerável é alocado antes do cookie e variáveis locais. Um estouro de buffer pode substituir esses parâmetros. E o código na função que usa esses parâmetros pode causar um ataque antes que a função retorna e a verificação de segurança é executada. Para minimizar esse risco, o compilador faz uma cópia dos parâmetros vulneráveis durante o prólogo da função e coloca-os abaixo da área de armazenamento de buffers.

O compilador não faz cópias dos parâmetros de vulnerabilidade nas seguintes situações:

- Funções que não contêm um buffer de GS.

- Otimizações ([/O opções](../../build/reference/o-options-optimize-code.md)) não estão habilitados.

- Funções que têm uma lista de argumentos variáveis (...).

- Funções que são marcadas com [naked](../../cpp/naked-cpp.md).

- Funções que contêm código de assembly embutido na primeira instrução.

- Um parâmetro é usado somente de maneiras que são menos prováveis de ser explorável no caso de uma saturação de buffer.

## <a name="what-is-not-protected"></a>O que não está protegido

O **/GS** opção de compilador não protege contra todos os ataques de segurança de estouro de buffer. Por exemplo, se você tiver um buffer e uma vtable em um objeto, um estouro de buffer pode corromper a vtable.

Mesmo se você usar **/GS**, tente sempre escrever código seguro com nenhum estouros de buffer.

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Na **Gerenciador de soluções**, clique com botão direito no projeto e, em seguida, clique em **propriedades**.

   Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. No **páginas de propriedades** caixa de diálogo, clique o **C/C++** pasta.

1. Clique o **geração de código** página de propriedades.

1. Modificar a **Buffer Security Check** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BufferSecurityCheck%2A>.

## <a name="example"></a>Exemplo

Este exemplo saturações de um buffer. Isso faz com que o aplicativo falhe em tempo de execução.

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

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
