---
title: "/MANIFESTDEPENDENCY (especificar depend&#234;ncias de manifesto) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.AdditionalManifestDependencies"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /MANIFESTDEPENDENCY"
  - "opção de vinculador MANIFESTDEPENDENCY"
  - "opção de vinculador -MANIFESTDEPENDENCY"
ms.assetid: e4b68313-33a2-4c3e-908e-ac2b9f7d6a73
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MANIFESTDEPENDENCY (especificar depend&#234;ncias de manifesto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/MANIFESTDEPENDENCY:manifest_dependency  
```  
  
## Comentários  
 \/MANIFESTDEPENDENCY permite especificar atributos que serão colocados \<na seção\> de dependência do arquivo de manifesto.  
  
 Consulte [\/MANIFEST \(criar manifesto de assembly lado a lado\)](../../build/reference/manifest-create-side-by-side-assembly-manifest.md) para obter informações sobre como criar um arquivo de manifesto.  
  
 Para \<obter mais informações sobre a\> seção de dependência do arquivo de manifesto, consulte [Arquivos de configuração do publicador](http://msdn.microsoft.com/library/aa375682).  
  
 informações de \/MANIFESTDEPENDENCY pode ser passada ao vinculador de uma de duas maneiras:  
  
-   Diretamente na linha de comando \(ou em um arquivo de resposta\) com \/MANIFESTDEPENDENCY.  
  
-   Pelo pragma de [comentário](../../preprocessor/comment-c-cpp.md) .  
  
 O exemplo a seguir mostra um comentário de \/MANIFESTDEPENDENCY submetida ao pragma,  
  
```  
#pragma comment(linker, "\"/manifestdependency:type='Win32' name='Test.Research.SampleAssembly' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='0000000000000000' language='*'\"")  
```  
  
 que resulta na seguinte entrada no arquivo de manifesto:  
  
```  
<dependency>  
  <dependentAssembly>  
    <assemblyIdentity type='Win32' name='Test.Research.SampleAssembly' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='0000000000000000' language='*' />  
  </dependentAssembly>  
</dependency>  
```  
  
 Os mesmos comentários de \/MANIFESTDEPENDENCY podem ser transmitidos na linha de comando como segue:  
  
```  
"/manifestdependency:type='Win32' name='Test.Research.SampleAssembly' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='0000000000000000' language='*'\"  
```  
  
 O vinculador coletará comentários de \/MANIFESTDEPENDENCY, elimina entradas duplicadas, e depois adiciona a cadeia de caracteres XML resultante no arquivo de manifesto.  Se o vinculador localiza conflitante entradas, o arquivo de manifesto se tornará corrompido e o aplicativo não iniciará \(uma entrada pode ser adicionada ao log de eventos, indicando que a origem da falha\).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades de **Arquivo de Manifesto** .  
  
5.  Modifique a propriedade de **Dependências de Manifesto Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalManifestDependencies%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)