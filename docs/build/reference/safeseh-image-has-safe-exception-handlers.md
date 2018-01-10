---
title: "-SAFESEH (a imagem tem manipuladores de exceção seguros) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /SAFESEH
dev_langs: C++
helpviewer_keywords:
- /SAFESEH linker option
- -SAFESEH linker option
- SAFESEH linker option
ms.assetid: 7722ff99-b833-4c65-a855-aaca902ffcb7
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1c57a882e3a421d03b2edf97c9fb4bf2f352e5d5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="safeseh-image-has-safe-exception-handlers"></a>/SAFESEH (a imagem tem manipuladores de exceção seguros)
```  
/SAFESEH[:NO]  
```  
  
 Quando **/SAFESEH** for especificado, o vinculador só produzirá uma imagem caso possa também produzir uma tabela dos manipuladores de exceção segura da imagem. Esta tabela especifica para o sistema operacional quais manipuladores de exceção são válidos para a imagem.  
  
 **/SafeSEH** só é válido ao vincular para x86 de destinos. **/SafeSEH** não há suporte para plataformas que já tem os manipuladores de exceção observados. Por exemplo, em [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] e ARM, exceção todos os manipuladores estão destacados em PDATA. ML64.exe tem suporte para adicionar anotações que emitir informações de SEH (XDATA e PDATA) na imagem, permitindo que você desenrolar por meio das funções ml64. Consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md) para obter mais informações.  
  
 Se **/SAFESEH** não for especificado, o vinculador produzirá uma imagem com uma tabela de manipuladores de exceções de segurança se todos os módulos são compatíveis com o recurso de manipulação de exceção segura. Se todos os módulos não eram compatíveis com o recurso de manipulação de exceção de segurança, a imagem resultante não conterá uma tabela de manipuladores de exceção de segurança. Se [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) Especifica WINDOWSCE ou uma das opções de EFI_ *, o vinculador não tentará produzir uma imagem com uma tabela de manipuladores de exceções de segurança, como nenhuma aos subsistemas pode fazer uso das informações.  
  
 Se **/SAFESEH:NO** for especificado, o vinculador não produzirá uma imagem com uma tabela de manipuladores de exceções de segurança mesmo que todos os módulos são compatíveis com o recurso de manipulação de exceções seguro.  
  
 O motivo mais comum para o vinculador para não ser capaz de gerar uma imagem é porque um ou mais dos arquivos de entrada (módulos) para o vinculador não era compatível com o recurso de manipuladores de exceção de segurança. Um motivo comum para um módulo não seja compatível com os manipuladores de exceção segura é porque ele foi criado com um compilador de uma versão anterior do Visual C++.  
  
 Você também pode registrar uma função como um manipulador de exceção estruturada usando [. SAFESEH](../../assembler/masm/dot-safeseh.md).  
  
 Não é possível marcar um arquivo binário como tendo exceção segura manipuladores (ou não há manipuladores de exceção) obter informações sobre a manipulação de exceção segura devem ser adicionadas no momento da compilação.  
  
 A capacidade do vinculador para criar uma tabela de manipuladores de exceção de segurança depende do aplicativo usando a biblioteca de tempo de execução C. Se você vincular com [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) e quiser uma tabela de manipuladores de exceção de segurança, você precisa fornecer uma estrutura de configuração de carga (por exemplo, pode ser encontrado no arquivo de origem loadcfg.c CRT) que contém todas as entradas definidas para o Visual C++. Por exemplo:  
  
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
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Insira a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)