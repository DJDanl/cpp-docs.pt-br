---
title: "Arquivos .Lib como entrada de vinculador | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.AdditionalDependencies"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .lib"
  - "arquivos COFF, importar bibliotecas"
  - "bibliotecas padrão [C++]"
  - "bibliotecas padrão [C++], saída de vinculador"
  - "padrões [C++], bibliotecas"
  - "importar bibliotecas, arquivos de vinculador"
  - "bibliotecas [C++], Arquivos .lib como entrada de vinculador"
  - "vinculando [C++], bibliotecas OMF"
  - "bibliotecas OMF"
ms.assetid: dc5d2b1c-2487-41fa-aa71-ad1e0647958b
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos .Lib como entrada de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O LINK aceita as bibliotecas padrão das bibliotecas de COFF e de importação de COFF, que geralmente têm a extensão .lib.  As bibliotecas padrão contêm objetos e são criadas pela ferramenta de LIB.  As bibliotecas de importação contêm informações sobre seguinte exporta em outros programas e são criadas por qualquer um LINK quando o compila um programa que contém exporta ou pela ferramenta de LIB.  Para obter informações sobre como usar o LIB para criar o padrão ou importar bibliotecas, consulte [Referência de LIB](../../build/reference/lib-reference.md).  Para obter detalhes sobre como usar o LINK para criar uma biblioteca de importação, consulte a opção de [\/DLL](../../build/reference/dll-build-a-dll.md) .  
  
 Uma biblioteca é especificada COMO VINCULAR como um argumento de nome de arquivo ou uma biblioteca padrão.  O LINK resolver referências externas procurando primeiro em bibliotecas especificadas na linha de comando, então em bibliotecas padrão especificada com a opção de [\/DEFAULTLIB](../../build/reference/defaultlib-specify-default-library.md) , em bibliotecas padrão e nomeadas em arquivos de .obj.  Se for especificado um caminho com o nome da biblioteca, o LINK na biblioteca nesse diretório.  Se nenhum caminho for especificado, o LINK procura primeiro no diretório que o LINK está executando do e, em todos os diretórios especificados na variável de ambiente de LIB.  
  
### Para adicionar arquivos de .lib como o vinculador entrou no ambiente de desenvolvimento  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Entrada** .  
  
4.  Modifique a propriedade de **Dependências Adicionais** .  
  
### Para adicionar arquivos programaticamente de .lib como a entrada do vinculador  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalDependencies%2A>.  
  
## Exemplo  
 O exemplo a seguir mostra como criar e usar um arquivo de .lib:  
  
```  
// lib_link_input_1.cpp  
// compile with: /LD  
__declspec(dllexport) int Test() {  
   return 213;  
}  
```  
  
## Exemplo  
 E depois:  
  
```  
// lib_link_input_2.cpp  
// compile with: /EHsc lib_link_input_1.lib  
__declspec(dllimport) int Test();  
#include <iostream>  
int main() {  
   std::cout << Test() << std::endl;  
}  
```  
  
  **213**   
## Consulte também  
 [Arquivos de entrada LINK](../../build/reference/link-input-files.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)