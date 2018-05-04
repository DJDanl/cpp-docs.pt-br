---
title: -hotpatch (Criar imagem Hotpatchable) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /hotpatch
- VC.Project.VCCLCompilerTool.CreateHotpatchableImage
dev_langs:
- C++
helpviewer_keywords:
- hot patching
- -hotpatch compiler option [C++]
- /hotpatch compiler option [C++]
- hotpatching
ms.assetid: aad539b6-c053-4c78-8682-853d98327798
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cb0f27c8da03104ee3633d9ea1a5f1232407931e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="hotpatch-create-hotpatchable-image"></a>/hotpatch (Criar imagem hotpatchable)
Prepara uma imagem para patch instantâneo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/hotpatch  
```  
  
## <a name="remarks"></a>Comentários  
 Quando **/hotpatch** é usado em uma compilação, o compilador garante a primeira instrução de cada função é pelo menos dois bytes, que é exigido para aplicação de patch ativa.  
  
 Para concluir a preparação para fazer hotpatchable uma imagem, depois de usar **/hotpatch** para compilar, você deve usar [/FUNCTIONPADMIN (Criar imagem de Hotpatchable)](../../build/reference/functionpadmin-create-hotpatchable-image.md) para vincular. Quando você compilar e vincular uma imagem usando uma chamada de cl.exe, **/hotpatch** implica **/functionpadmin**.  
  
 Porque as instruções são sempre de dois bytes ou maior na arquitetura ARM e porque x64 compilação sempre é tratada como se **/hotpatch** tiver sido especificado, você não precisa especificar **/hotpatch** quando compilar para esses destinos; No entanto, você ainda deve vincular usando **/functionpadmin** criar imagens hotpatchable para eles. O **/hotpatch** compilador opção só afeta x86 compilação.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Adicione a opção de compilador para o **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="guidance"></a>Diretrizes  
 Para obter mais informações sobre o gerenciamento de atualização, consulte "Diretrizes para atualização de gerenciamento de segurança" em [ http://www.microsoft.com/technet/security/guidance/PatchManagement.mspx ](http://www.microsoft.com/technet/security/guidance/PatchManagement.mspx).  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)