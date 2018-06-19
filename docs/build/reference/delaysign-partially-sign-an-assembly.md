---
title: -DELAYSIGN (assinar parcialmente um Assembly) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /delaysign
- VC.Project.VCLinkerTool.DelaySign
dev_langs:
- C++
helpviewer_keywords:
- /DELAYSIGN linker option
- DELAYSIGN linker option
- -DELAYSIGN linker option
ms.assetid: 15244d30-3ecb-492f-a408-ffe81f38de20
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eda1f426f24dd63684fd6831e2efef6838c43a3d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32375058"
---
# <a name="delaysign-partially-sign-an-assembly"></a>/DELAYSIGN (assinar parcialmente um assembly)
```  
/DELAYSIGN[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 NÃO  
 Especifica que o assembly não deve ser parcialmente assinado.  
  
## <a name="remarks"></a>Comentários  
 Use **/DELAYSIGN** se você deseja colocar a chave pública no assembly. O padrão é **/delaysign: no**.  
  
 O **/DELAYSIGN** opção não tem nenhum efeito a menos que usado com [/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) ou [/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md).  
  
 Quando você solicita um assembly totalmente assinado, o compilador usa o hash no arquivo que contém o manifesto (metadados de assembly) e sinaliza esse hash com a chave particular. A assinatura digital resultante é armazenada no arquivo que contém o manifesto. Quando um assembly é assinado com atraso, o vinculador não calcular e armazenar a assinatura, mas reserva espaço no arquivo de forma a assinatura pode ser adicionada posteriormente.  
  
 Por exemplo, usando **/DELAYSIGN** permite que um testador colocar o assembly no cache global. Depois de testes, você pode assinar totalmente o assembly, colocando a chave privada no assembly.  
  
 Consulte [Assemblies com nome forte (assinatura de Assembly) (C + + CLI)](../../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md) e [atraso assinar um Assembly](/dotnet/framework/app-domains/delay-sign-assembly) para obter mais informações sobre como assinar um assembly.  
  
 Outras opções de vinculador que afetam a geração de assembly são:  
  
-   [/ASSEMBLYDEBUG](../../build/reference/assemblydebug-add-debuggableattribute.md)  
  
-   [/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)  
  
-   [/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)  
  
-   [/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)  
  
-   [/ NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)