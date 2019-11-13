---
title: MASM para x64 (ml64.exe)
ms.date: 08/30/2018
helpviewer_keywords:
- ml64
- ml64.exe
- masm for x64
ms.assetid: 89059103-f372-4968-80ea-0c7f90bb9c91
ms.openlocfilehash: d9b550313c8e65e47db70dc81519abce7db95da5
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74050183"
---
# <a name="masm-for-x64-ml64exe"></a>MASM para x64 (ml64.exe)

O Visual Studio inclui versões hospedadas de 32 bits e 64 bits do Microsoft assembler (MASM) para direcionar o código x64. Chamado ml64. exe, este é o montador que aceita a linguagem x64 Assembler. As ferramentas de linha de comando MASM são instaladas quando você C++ escolhe uma carga de trabalho durante a instalação do Visual Studio. As ferramentas do MASM não estão disponíveis como um download separado. Para obter instruções sobre como baixar e instalar uma cópia do Visual Studio, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio). Se você não quiser instalar o IDE completo do Visual Studio, mas quiser apenas as ferramentas de linha de comando, baixe as [ferramentas de Build para o Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019).

Para usar o MASM para criar código para destinos x64 na linha de comando, você deve usar um prompt de comando do desenvolvedor para destinos x64, que define o caminho necessário e outras variáveis de ambiente. Para obter informações sobre como iniciar um prompt de comando do desenvolvedor, consulte [criarC++ C/Code na linha de comando](../../build/building-on-the-command-line.md).

Para obter informações sobre opções de linha de comando do ml64. exe, consulte [referência de linha de comando ml e ml64](../../assembler/masm/ml-and-ml64-command-line-reference.md).

O Assembler embutido ou o uso da palavra-chave ASM não tem suporte para destinos x64 ou ARM. Para portar seu código x86 que usa o Assembler embutido para x64 ou ARM, você pode C++converter seu código para, usar intrínsecos do compilador ou criar arquivos de origem do assembler-Language. O compilador C++ da Microsoft dá suporte a intrínsecos para permitir que você use instruções de função especial, por exemplo, com privilégios, verificação/teste de bits, intercadeados e assim por diante, no mais próximo possível de uma plataforma cruzada. Para obter informações sobre intrínsecos disponíveis, consulte [intrínsecos do compilador](../../intrinsics/compiler-intrinsics.md).

## <a name="add-an-assembler-language-file-to-a-visual-studio-c-project"></a>Adicionar um arquivo Assembler-Language a um projeto C++ do Visual Studio

O sistema de projeto do Visual Studio dá suporte a arquivos de linguagem assembler criados C++ usando MASM em seus projetos. Você pode criar arquivos de origem do assembler x64 e compilá-los em arquivos de objeto usando o MASM, que dá suporte totalmente a x64. Em seguida, você pode vincular esses arquivos de C++ objeto ao seu código criado para destinos x64. Essa é uma maneira de superar a falta de um montador em x64 embutido.

### <a name="to-add-an-assembler-language-file-to-an-existing-visual-studio-c-project"></a>Para adicionar um arquivo Assembler-Language a um projeto existente C++ do Visual Studio

1. Selecione o projeto no **Gerenciador de Soluções**. Na barra de menus, escolha **projeto**, **criar personalizações**.

1. Na caixa de diálogo **arquivos de personalização de compilação Visual C++**  , marque a caixa de seleção ao lado de **MASM (. targets,. props)** . Escolha **OK** para salvar sua seleção e fechar a caixa de diálogo.

1. Na barra de menus, escolha **projeto**, **Adicionar novo item**.

1. Na caixa de diálogo **Adicionar novo item** , selecione  **C++ arquivo (. cpp)** no painel central. No controle **nome** de edição, insira um novo nome de arquivo que tenha uma extensão **. asm** em vez de. cpp. Escolha **Adicionar** para adicionar o arquivo ao seu projeto e feche a caixa de diálogo.

Crie seu código de idioma do assembler no arquivo. asm que você adicionou. Quando você cria sua solução, o MASM Assembler é invocado para montar o arquivo. asm em um arquivo de objeto que é vinculado ao seu projeto. Para facilitar o acesso ao símbolo, declare suas funções do assembler como C++ `extern "C"` em seu código-fonte, C++ em vez de usar as convenções de decoração de nome em seus arquivos de origem do assembler-Language.

## <a name="ml64-specific-directives"></a>Diretivas específicas do ml64

Você pode usar as seguintes diretivas específicas do ml64 em seu código-fonte do assembler-Language direcionado para x64:

- [.ALLOCSTACK](../../assembler/masm/dot-allocstack.md)

- [.ENDPROLOG](../../assembler/masm/dot-endprolog.md)

- [.PUSHFRAME](../../assembler/masm/dot-pushframe.md)

- [.PUSHREG](../../assembler/masm/dot-pushreg.md)

- [.SAVEREG](../../assembler/masm/dot-savereg.md)

- [.SAVEXMM128](../../assembler/masm/dot-savexmm128.md)

- [.SETFRAME](../../assembler/masm/dot-setframe.md)

Além disso, a diretiva [proc](../../assembler/masm/proc.md) foi atualizada para uso com ml64. exe.

## <a name="32-bit-address-mode-address-size-override"></a>Modo de endereço de 32 bits (substituição do tamanho do endereço)

MASM emitirá a substituição do tamanho do endereço 0x67 se um operando de memória incluir registros de 32 bits. Por exemplo, os exemplos a seguir fazem com que a substituição do tamanho do endereço seja emitida:

```asm
mov rax, QWORD PTR [ecx]
mov eax, DWORD PTR [ecx*2+r10d]
mov eax, DWORD PTR [ecx*2+r10d+0100h]
prefetch [eax]
movnti rax, QWORD PTR [r8d]
```

MASM pressupõe que se um deslocamento de 32 bits aparecer sozinho como um operando de memória, o endereçamento de 64 bits será pretendido. Atualmente, não há suporte para endereçamento de 32 bits com esses operandos.

Por fim, misturar tamanhos de registro dentro de um operando de memória, conforme demonstrado no código a seguir, gera um erro.

```asm
mov eax, DWORD PTR [rcx*2+r10d]
mov eax, DWORD PTR [ecx*2+r10+0100h]
```

## <a name="see-also"></a>Consulte também

[Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)<br/>