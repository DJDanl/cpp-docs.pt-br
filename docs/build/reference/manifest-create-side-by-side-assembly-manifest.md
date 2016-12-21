---
title: "/MANIFEST (criar manifesto de assembly lado a lado) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.GenerateManifest"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /MANIFEST"
  - "opção de vinculador MANIFEST"
  - "opção de vinculador -MANIFEST"
ms.assetid: 98c52e1e-712c-4f49-b149-4d0a3501b600
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MANIFEST (criar manifesto de assembly lado a lado)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/MANIFEST[:{EMBED[,ID=#]|NO}]  
```  
  
## Comentários  
 \/MANIFEST especifica que o vinculador deve criar um arquivo de manifesto lado a lado.  Para obter mais informações sobre os arquivos de manifesto, consulte [Referência do arquivo de manifesto](http://msdn.microsoft.com/library/aa375632).  
  
 A opção é \/MANIFEST.  
  
 A opção de \/MANIFEST:EMBED especifica que o vinculador deve digitar o arquivo de manifesto na imagem como um recurso do tipo RT\_MANIFEST.  O parâmetro opcional de `ID` é a ID do recurso a ser usado para o manifesto.  Use um valor de 1 para um arquivo executável.  Use um valor de 2 para uma DLL que permite especificar dependências privadas.  Se o parâmetro de `ID` não for especificado, o valor padrão é 2 se a opção \/DLL for definida; caso contrário, o valor padrão é 1.  
  
 A partir [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], os arquivos de manifesto para executáveis contêm uma seção que especifica as informações de Controle de Conta de Usuário \(UAC\).  Se você especificar \/MANIFEST mas não especifica nem [\/MANIFESTUAC](../../build/reference/manifestuac-embeds-uac-information-in-manifest.md) ou [\/DLL](../../build/reference/dll-build-a-dll.md), um fragmento do UAC opção que tem o nível do UAC definido *como asInvoker* é inserido no manifesto.  Para obter mais informações sobre os níveis do UAC, consulte [\/MANIFESTUAC \(insere informações UAC no manifesto\)](../../build/reference/manifestuac-embeds-uac-information-in-manifest.md).  
  
 Para alterar o comportamento padrão para o UAC, siga um destes:  
  
-   Especifique a opção \/MANIFESTUAC e define o nível do UAC para o valor desejado.  
  
-   Ou especificar a opção de \/MANIFESTUAC:NO se não desejar gerar um fragmento do UAC no manifesto.  
  
 Se você não especificar \/MANIFEST mas especifica comentários de [\/MANIFESTDEPENDENCY](../../build/reference/manifestdependency-specify-manifest-dependencies.md) , um arquivo de manifesto é criado.  Um arquivo de manifesto não é criado se você especificar \/MANIFEST:NO.  
  
 Se você especificar \/MANIFEST, o nome do arquivo de manifesto é o mesmo que o nome do arquivo de saída, mas com o .manifest anexado ao nome de arquivo.  Por exemplo, se o nome do arquivo de saída é MyFile.exe, o nome do arquivo de manifesto é MyFile.exe.manifest.  Se você especificar \/MANIFESTFILE:*name*, o nome do manifesto é o que você especifica em *name*.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades de **Arquivo de Manifesto** .  
  
5.  Modifique a propriedade de **Gerar Manifesto** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateManifest%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)