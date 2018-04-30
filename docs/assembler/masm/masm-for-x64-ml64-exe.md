---
title: MASM para x64 (ml64.exe) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ml64
- ml64.exe
- masm for x64
ms.assetid: 89059103-f372-4968-80ea-0c7f90bb9c91
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b17771239ff9c89b765576ba49515463db42386f
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="masm-for-x64-ml64exe"></a>MASM para x64 (ml64.exe)

O Visual Studio inclui 32 bits e 64 bits versões hospedadas de MASM para o código de destino x64. Chamado ml64.exe, este é o assembler que aceita x64 linguagem assembler. As ferramentas de linha de comando (MASM) são instaladas quando você escolhe uma carga de trabalho C++ durante a instalação do Visual Studio. Essas ferramentas não estão disponíveis como um download separado. Para baixar e instalar uma cópia do Visual Studio, consulte [ https://www.visualstudio.com/ ](https://www.visualstudio.com/). Se você não quiser instalar o Visual Studio IDE, mas desejar somente as ferramentas de linha de comando, consulte o **Build Tools para Visual Studio de 2017** opção o [Downloads do Visual Studio](https://www.visualstudio.com/downloads/) página.

Usar MASM para compilar código para x64 tem como alvo na linha de comando, você deve usar um prompt de comando do desenvolvedor para x64 destinos, que define o caminho necessário e outras variáveis de ambiente. Para obter informações sobre como iniciar um prompt de comando do desenvolvedor, consulte [código C/C++ compilar na linha de comando](../../build/building-on-the-command-line.md).

Para obter informações sobre opções de linha de comando ml64.exe, consulte [ML e ML64 Referência de linha de comando](../../assembler/masm/ml-and-ml64-command-line-reference.md).  
  
Assembler embutido ou o uso da palavra-chave ASM não há suporte para x64 ou ARM público-alvo. A porta de seu x86 código assembler de embutido que usa para x64 ou ARM, você pode converter seu código em C++, use intrínsecos do compilador ou criar linguagem assembler arquivos de origem. O compilador do Visual C++ dá suporte a intrínsecos para permitir que você use instruções de função especial de exemplo, privilegiado, bits de verificação/teste, interligada e assim por diante, no como perto de uma maneira em plataforma cruzada possível. Para obter informações sobre disponíveis intrínsecos, consulte [intrínsecos do compilador](../../intrinsics/compiler-intrinsics.md).  

## <a name="add-an-assembler-language-file-to-a-visual-c-project"></a>Adicionar um arquivo de linguagem assembler para um projeto do Visual C++  
  
O sistema de projeto do Visual Studio dá suporte a arquivos de idioma do assembler criados usando MASM em seus projetos do C++. Você pode criar arquivos de fonte da linguagem assembler e criá-los em arquivos de objeto usando MASM, que dá suporte a x64 totalmente de x64. Em seguida, você pode vincular esses arquivos de objeto no código C++ compilado para x64 destinos. Essa é uma maneira para superar a falta de x64 assembler embutido.  

### <a name="to-add-an-assembler-language-file-to-an-existing-visual-c-project"></a>Para adicionar um arquivo de linguagem assembler a um projeto existente do Visual C++

1. Selecione o projeto na **Gerenciador de soluções**. Na barra de menus, escolha **projeto**, **criar personalizações**.

1. No **Visual C++ criar arquivos de personalização** caixa de diálogo caixa, marque a caixa de seleção ao lado **masm(.targets,.props)**. Escolha **Okey** para salvar sua seleção e fechar a caixa de diálogo.

1. Na barra de menus, escolha **projeto**, **Adicionar Novo Item**. 

1. No **Adicionar Novo Item** caixa de diálogo, selecione **arquivo C++ (. cpp)** no painel central. No **nome** controle de edição, digite um novo nome de arquivo que tenha um **. ASM** extensão em vez. cpp. Escolha **adicionar** para adicionar o arquivo ao seu projeto e fechar a caixa de diálogo.

Crie seu código de idioma do assembler no arquivo. ASM adicionado. Quando você cria sua solução, o assembler (MASM) é chamado para montar o arquivo. ASM em um arquivo de objeto que é vinculado ao seu projeto. Para facilitar o acesso do símbolo, declare funções assembler como `extern "C"` no seu código-fonte C++, em vez de usar o C++ nome convenções de decoração em seu idioma assembler arquivos de origem.
  
## <a name="ml64-specific-directives"></a>Diretivas de ml64 específico  

Você pode usar as seguintes diretivas ml64 específicos em seu código-fonte assembler linguagem que tem como alvo x64:  
  
-   [.ALLOCSTACK](../../assembler/masm/dot-allocstack.md)  
  
-   [.ENDPROLOG](../../assembler/masm/dot-endprolog.md)  
  
-   [.PUSHFRAME](../../assembler/masm/dot-pushframe.md)  
  
-   [.PUSHREG](../../assembler/masm/dot-pushreg.md)  
  
-   [.SAVEREG](../../assembler/masm/dot-savereg.md)  
  
-   [.SAVEXMM128](../../assembler/masm/dot-savexmm128.md)  
  
-   [.SETFRAME](../../assembler/masm/dot-setframe.md)  
  
Além disso, o [PROC](../../assembler/masm/proc.md) diretiva foi atualizada para uso com ml64.exe.  
  
## <a name="32-bit-address-mode-address-size-override"></a>Modo de endereçamento de 32 bits (substituição de tamanho de endereço)  

MASM emite a substituição de tamanho de endereço 0x67 se um operando de memória inclui registros de 32 bits. Por exemplo, os exemplos a seguir fazem a substituição de tamanho de endereço ser emitida:  
  
```MASM  
mov rax, QWORD PTR [ecx]  
mov eax, DWORD PTR [ecx*2+r10d]  
mov eax, DWORD PTR [ecx*2+r10d+0100h]  
prefetch [eax]  
movnti rax, QWORD PTR [r8d]  
```  
  
MASM pressupõe que se um deslocamento de 32 bits aparece apenas como um operando de memória, o endereçamento de 64 bits é destinado. Atualmente, não há nenhum suporte para endereçamento de 32 bits com esses operandos.  
  
Por fim, a combinação de tamanhos de registro em um operando de memória, conforme demonstrado no código a seguir gera um erro.  
  
```MASM  
mov eax, DWORD PTR [rcx*2+r10d]  
mov eax, DWORD PTR [ecx*2+r10+0100h]  
```  
  
## <a name="see-also"></a>Consulte também  

[Referência do Microsoft Macro Assembler](../../assembler/masm/microsoft-macro-assembler-reference.md)