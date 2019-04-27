---
title: MASM para x64 (ml64.exe)
ms.date: 08/30/2018
helpviewer_keywords:
- ml64
- ml64.exe
- masm for x64
ms.assetid: 89059103-f372-4968-80ea-0c7f90bb9c91
ms.openlocfilehash: 0404bff54a08988a72fcb0a0c075a4446bf90f48
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62178235"
---
# <a name="masm-for-x64-ml64exe"></a>MASM para x64 (ml64.exe)

Visual Studio inclui 32 bits e 64 bits versões hospedadas do Microsoft Assembler (MASM) para o código de destino x64. Chamado ml64.exe, isso é o assembler que aceita x64 linguagem assembler. As ferramentas de linha de comando (MASM) são instaladas quando você escolhe uma carga de trabalho do C++ durante a instalação do Visual Studio. As ferramentas MASM não estão disponíveis como um download separado. Para obter instruções sobre como baixar e instalar uma cópia do Visual Studio, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio). Se você não deseja instalar o Visual Studio IDE completo, mas apenas deseja que as ferramentas de linha de comando, baixe o [ferramentas de Build do Visual Studio 2017](https://go.microsoft.com/fwlink/p/?linkid=875721).

Para usar MASM para compilar código para x64, tem como alvo na linha de comando, você deve usar um prompt de comando do desenvolvedor para x64 destinos, que define o caminho necessário e outras variáveis de ambiente. Para obter informações sobre como iniciar um prompt de comando do desenvolvedor, consulte [código de compilação C/C++ na linha de comando](../../build/building-on-the-command-line.md).

Para obter informações sobre opções de linha de comando ml64.exe, consulte [ML e ML64 Referência de linha de comando](../../assembler/masm/ml-and-ml64-command-line-reference.md).

Assembler embutido ou o uso da palavra-chave do ASM, não há suporte para x64 ou ARM público-alvo. Portar seu x86 que assembler embutido de usos de código para x64 ou ARM, você pode converter seu código em C++, use intrínsecos do compilador ou criar arquivos de origem de idioma do assembler. O compilador do Visual C++ dá suporte a intrínsecos para permitir que você use instruções de função especial para verificação/teste, interconectada e assim por diante, em como perto de uma maneira em plataforma cruzada possível de bits de exemplo, privilegiado. Para obter informações sobre intrínsecos disponíveis, consulte [intrínsecos do compilador](../../intrinsics/compiler-intrinsics.md).

## <a name="add-an-assembler-language-file-to-a-visual-c-project"></a>Adicionar um arquivo de linguagem assembler a um projeto do Visual C++

O sistema de projeto do Visual Studio dá suporte a arquivos de idioma do assembler criados por meio de MASM em seus projetos C++. Você pode criar arquivos de origem de idioma de montador e criá-los em arquivos de objeto usando-se (MASM), que dá suporte a x64 totalmente de x64. Em seguida, você pode vincular esses arquivos de objeto para o seu código C++ compilado para x64 destinos. Isso é uma maneira de superar a falta de x64 assembler embutido.

### <a name="to-add-an-assembler-language-file-to-an-existing-visual-c-project"></a>Para adicionar um arquivo de linguagem assembler a um projeto existente do Visual C++

1. Selecione o projeto no **Gerenciador de Soluções**. Na barra de menus, escolha **Project**, **personalizações da compilação**.

1. No **Visual C++ compilar arquivos de personalização** diálogo caixa, marque a caixa de seleção ao lado **masm(.targets,.props)**. Escolher **Okey** para salvar sua seleção e fechar a caixa de diálogo.

1. Na barra de menus, escolha **Project**, **Adicionar Novo Item**.

1. No **Adicionar Novo Item** caixa de diálogo, selecione **arquivo do C++ (. cpp)** no painel central. No **nome** controle de edição, digite um novo nome de arquivo que tem um **ASM** extensão em vez. cpp. Escolher **adicionar** para adicionar o arquivo ao seu projeto e fechar a caixa de diálogo.

Crie seu código de assembler idioma no arquivo de. ASM que você adicionou. Quando você compila sua solução, o assembler (MASM) é invocado para montar o arquivo. ASM em um arquivo de objeto, em seguida, é vinculado ao seu projeto. Para facilitar o acesso de símbolo, declarar suas funções de montador como `extern "C"` seu código-fonte C++, em vez de usar o C++ nomeia convenções decoration em sua linguagem de montador arquivos de origem.

## <a name="ml64-specific-directives"></a>Diretivas específicas ml64

Você pode usar as seguintes diretivas ml64 específicos em seu código-fonte assembler linguagem que tem como alvo x64:

- [.ALLOCSTACK](../../assembler/masm/dot-allocstack.md)

- [.ENDPROLOG](../../assembler/masm/dot-endprolog.md)

- [.PUSHFRAME](../../assembler/masm/dot-pushframe.md)

- [.PUSHREG](../../assembler/masm/dot-pushreg.md)

- [.SAVEREG](../../assembler/masm/dot-savereg.md)

- [.SAVEXMM128](../../assembler/masm/dot-savexmm128.md)

- [.SETFRAME](../../assembler/masm/dot-setframe.md)

Além disso, o [PROC](../../assembler/masm/proc.md) diretiva foi atualizada para uso com ml64.exe.

## <a name="32-bit-address-mode-address-size-override"></a>Modo de endereço de 32 bits (substituição de tamanho de endereço)

MASM emite a substituição de tamanho de endereço 0x67 se um operando de memória inclui registros de 32 bits. Por exemplo, os exemplos a seguir fazem com que a substituição de tamanho de endereço a ser emitida:

```asm
mov rax, QWORD PTR [ecx]
mov eax, DWORD PTR [ecx*2+r10d]
mov eax, DWORD PTR [ecx*2+r10d+0100h]
prefetch [eax]
movnti rax, QWORD PTR [r8d]
```

MASM pressupõe que se um deslocamento de 32 bits é exibido apenas como um operando de memória, tratamento de 64 bits destina-se. Atualmente, não há nenhum suporte para endereçamento de 32 bits com esses operandos.

Por fim, a mistura de tamanhos de registro dentro de um operando de memória, conforme demonstrado no código a seguir gera um erro.

```asm
mov eax, DWORD PTR [rcx*2+r10d]
mov eax, DWORD PTR [ecx*2+r10+0100h]
```

## <a name="see-also"></a>Consulte também

[Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)<br/>