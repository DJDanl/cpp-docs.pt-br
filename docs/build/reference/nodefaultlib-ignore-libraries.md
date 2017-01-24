---
title: "/NODEFAULTLIB (ignorar bibliotecas) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.IgnoreAllDefaultLibraries"
  - "VC.Project.VCLinkerTool.IgnoreDefaultLibraryNames"
  - "/nodefaultlib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /NODEFAULTLIB"
  - "bibliotecas padrão, removendo"
  - "opção de vinculador ignorar bibliotecas"
  - "bibliotecas, ignorar"
  - "opção de vinculador NODEFAULTLIB"
  - "opção de vinculador -NODEFAULTLIB"
ms.assetid: 7270b673-6711-468e-97a7-c2925ac2be6e
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /NODEFAULTLIB (ignorar bibliotecas)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/NODEFAULTLIB[:library]   
```  
  
## Comentários  
 onde:  
  
 *biblioteca*  
 Uma biblioteca desejada o vinculador para ignorar quando ele resolver referências externas.  
  
## Comentários  
 A opção \/NODEFAULTLIB diz o vinculador para remover uma ou várias bibliotecas padrão da lista de bibliotecas que pesquisa ao resolver referências externas.  
  
 Para criar um .obj arquivo que não contém referências às bibliotecas padrão, use [\/Zl \(omitir nome da biblioteca padrão\)](../../build/reference/zl-omit-default-library-name.md).  
  
 Por padrão, \/NODEFAULTLIB remove todas as bibliotecas padrão da lista de bibliotecas que pesquisa ao resolver referências externas.  O parâmetro opcional da *biblioteca* permite remover uma biblioteca ou em bibliotecas especificadas na lista de bibliotecas que pesquisa ao resolver referências externas.  Especificar uma opção do \/NODEFAULTLIB para cada biblioteca que você deseja excluir.  
  
 O vinculador resolver referências às definições externos procurando primeiro em bibliotecas que você especifique explicitamente, então em bibliotecas padrão especificada com a opção \/DEFAULTLIB, em bibliotecas padrão e nomeadas em arquivos de .obj.  
  
 \/NODEFAULTLIB:*a biblioteca* substitui*a biblioteca* de [\/DEFAULTLIB:](../../build/reference/defaultlib-specify-default-library.md)quando o mesmo nome *da biblioteca* é especificado em ambos.  
  
 Se você usar \/NODEFAULTLIB, por exemplo, para criar seu programa sem a biblioteca de tempo de execução C, você pode ter que usar [\/ENTRY](../../build/reference/entry-entry-point-symbol.md) para especificar o ponto de entrada \(função\) em seu programa.  Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na páginade propriedades de **Entrada**.  
  
4.  Selecione a propriedade de **Ignorar Todas as Bibliotecas Padrão** ou especificar uma lista das bibliotecas que você quer ignorar na propriedade de **Ignorar Biblioteca Específica** .  A página de propriedades de **Linha de Comando** mostrará o efeito das alterações feitas nessas propriedades.  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreDefaultLibraryNames%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreAllDefaultLibraries%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)