---
title: -MANIFESTO (criar manifesto do Assembly lado a lado) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.GenerateManifest
dev_langs:
- C++
helpviewer_keywords:
- -MANIFEST linker option
- /MANIFEST linker option
- MANIFEST linker option
ms.assetid: 98c52e1e-712c-4f49-b149-4d0a3501b600
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5486eca41c93adb074cde6dc9602149d7dfa4f13
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32378308"
---
# <a name="manifest-create-side-by-side-assembly-manifest"></a>/MANIFEST (criar manifesto de assembly lado a lado)
```  
/MANIFEST[:{EMBED[,ID=#]|NO}]  
```  
  
## <a name="remarks"></a>Comentários  
 / MANIFESTO especifica que o vinculador deve criar um arquivo de manifesto lado a lado. Para obter mais informações sobre arquivos de manifesto, consulte [referência de arquivos de manifesto](http://msdn.microsoft.com/library/aa375632).  
  
 O padrão é /MANIFEST.  
  
 O /MANIFEST: Inserir opção especifica que o vinculador deve inserir o arquivo de manifesto na imagem como um recurso do tipo RT_MANIFEST. Opcional `ID` parâmetro é a ID de recurso a ser usado para o manifesto. Use um valor de 1 para um arquivo executável. Use um valor de 2 para uma DLL para habilitá-lo especificar dependências privadas. Se o `ID` parâmetro não for especificado, o valor padrão é 2, se a opção /DLL estiver definida; caso contrário, o valor padrão é 1.  
  
 Arquivos de manifesto para executáveis a partir do Visual Studio 2008, contém uma seção que especifica informações de controle de conta de usuário (UAC). Se você especificar /MANIFEST, mas não especificar nenhum [/MANIFESTUAC](../../build/reference/manifestuac-embeds-uac-information-in-manifest.md) nem [/DLL](../../build/reference/dll-build-a-dll.md), um fragmento UAC padrão que tem o conjunto de nível de UAC para *asInvoker* é inserido no manifesto. Para obter mais informações sobre os níveis UAC, consulte [/MANIFESTUAC (insere informações UAC no manifesto)](../../build/reference/manifestuac-embeds-uac-information-in-manifest.md).  
  
 Para alterar o comportamento padrão para o UAC, siga um destes procedimentos:  
  
-   Especifique a opção /MANIFESTUAC e defina o nível UAC para o valor desejado.  
  
-   Ou especifique a opção /MANIFESTUAC: no se você não deseja gerar um fragmento de UAC no manifesto.  
  
 Se você não especificar /MANIFEST, mas especificar [/MANIFESTDEPENDENCY](../../build/reference/manifestdependency-specify-manifest-dependencies.md) comentários, um arquivo de manifesto é criado. Um arquivo de manifesto não é criado se você especificar /MANIFEST:NO.  
  
 Se você especificar /MANIFEST, o nome do arquivo de manifesto é o mesmo que o nome do seu arquivo de saída, mas com. manifest junto ao nome do arquivo. Por exemplo, se o nome do arquivo de saída for MyFile.exe, o nome do arquivo de manifesto é MyFile.exe.manifest.  Se você especificar /MANIFESTFILE:*nome*, o nome do manifesto é o que você especificar na *nome*.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **o arquivo de manifesto** página de propriedades.  
  
5.  Modificar o **gerar manifesto** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateManifest%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)