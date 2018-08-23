---
title: -SAFESEH (a imagem tem manipuladores de exceção seguros) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /SAFESEH
dev_langs:
- C++
helpviewer_keywords:
- /SAFESEH linker option
- -SAFESEH linker option
- SAFESEH linker option
ms.assetid: 7722ff99-b833-4c65-a855-aaca902ffcb7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9156fd0d4d0433cfb975c242bc87008471bc4723
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42571829"
---
# <a name="safeseh-image-has-safe-exception-handlers"></a>/SAFESEH (a imagem tem manipuladores de exceção seguros)
```  
/SAFESEH[:NO]  
```  
  
 Quando **/SAFESEH** for especificado, o vinculador só produzirá uma imagem se ele também pode produzir uma tabela de manipuladores de exceção segura da imagem. Esta tabela especifica para o sistema operacional quais manipuladores de exceção são válidos para a imagem.  
  
 **/SafeSEH** só é válido ao vincular para x86 de destinos. **/SafeSEH** não há suporte para plataformas que já têm os manipuladores de exceção observados. Por exemplo, em x64 e ARM, todos os manipuladores de exceção são indicados na PDATA. ML64.exe tem suporte para adicionar anotações que emitam informações de SEH (XDATA e PDATA) na imagem, permitindo que você por meio de funções ml64 de desenrolamento. Ver [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md) para obter mais informações.  
  
 Se **/SAFESEH** não for especificado, o vinculador produzirá uma imagem com uma tabela de manipuladores de exceções seguro se todos os módulos são compatíveis com o recurso de manipulação de exceção segura. Se todos os módulos não eram compatíveis com o recurso de manipulação de exceção segura, a imagem resultante não conterá uma tabela de manipuladores de exceção segura. Se [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) Especifica WINDOWSCE ou uma das opções EFI_ *, o vinculador não tentará produzir uma imagem com uma tabela de manipuladores de exceções de segurança, como nenhuma aos subsistemas pode fazer uso das informações.  
  
 Se **/SAFESEH:NO** for especificado, o vinculador não produzirá uma imagem com uma tabela de manipuladores de exceções seguros mesmo se todos os módulos são compatíveis com a recurso de manipulação de exceção segura.  
  
 O motivo mais comum para o vinculador não deve ser capaz de produzir uma imagem é porque um ou mais dos arquivos de entrada (módulos) para o vinculador não era compatível com o recurso de manipuladores de exceção segura. Uma razão comum para um módulo não seja compatível com os manipuladores de exceção segura é porque ele foi criado com um compilador de uma versão anterior do Visual C++.  
  
 Você também pode registrar uma função como um manipulador de exceção estruturada usando [. SAFESEH](../../assembler/masm/dot-safeseh.md).  
  
 Não é possível marcar uma existente binário como a existência de exceção segura manipuladores (ou no nenhum manipuladores de exceção); informações sobre a manipulação de exceção segura devem ser adicionadas no momento da compilação.  
  
 A capacidade do vinculador para criar uma tabela de manipuladores de exceção segura depende do aplicativo usando a biblioteca de tempo de execução C. Se você vincular [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) e quiser uma tabela de manipuladores de exceção segura, você precisa fornecer uma estrutura de configuração de carga (por exemplo, pode ser encontrado no arquivo de origem loadcfg.c CRT) que contém todas as entradas definidas para o Visual C++. Por exemplo:  
  
```  
#include <windows.h>  
extern DWORD_PTR __security_cookie;  /* /GS security cookie */  
  
/*  
 * The following two names are automatically created by the linker for any  
 * image that has the safe exception table present.  
*/  
  
extern PVOID __safe_se_handler_table[]; /* base of safe handler entry table */  
extern BYTE  __safe_se_handler_count;  /* absolute symbol whose address is  
                                           the count of table entries */  
typedef struct {  
    DWORD       Size;  
    DWORD       TimeDateStamp;  
    WORD        MajorVersion;  
    WORD        MinorVersion;  
    DWORD       GlobalFlagsClear;  
    DWORD       GlobalFlagsSet;  
    DWORD       CriticalSectionDefaultTimeout;  
    DWORD       DeCommitFreeBlockThreshold;  
    DWORD       DeCommitTotalFreeThreshold;  
    DWORD       LockPrefixTable;            // VA  
    DWORD       MaximumAllocationSize;  
    DWORD       VirtualMemoryThreshold;  
    DWORD       ProcessHeapFlags;  
    DWORD       ProcessAffinityMask;  
    WORD        CSDVersion;  
    WORD        Reserved1;  
    DWORD       EditList;                   // VA  
    DWORD_PTR   *SecurityCookie;  
    PVOID       *SEHandlerTable;  
    DWORD       SEHandlerCount;  
} IMAGE_LOAD_CONFIG_DIRECTORY32_2;  
  
const IMAGE_LOAD_CONFIG_DIRECTORY32_2 _load_config_used = {  
    sizeof(IMAGE_LOAD_CONFIG_DIRECTORY32_2),  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    0,  
    &__security_cookie,  
    __safe_se_handler_table,  
    (DWORD)(DWORD_PTR) &__safe_se_handler_count  
};  
```  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Insira a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)