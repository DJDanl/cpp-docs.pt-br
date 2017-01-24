---
title: "/DLL (compilar uma DLL) | Microsoft Docs"
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
  - "/dll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DLL [C++]"
  - "opção de vinculador -DLL"
  - "opção de vinculador DLL [C++]"
  - "DLLs [C++], compilando"
  - "exportando DLLs [C++], especificando exportações"
ms.assetid: c7685aec-31d0-490f-9503-fb5171a23609
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DLL (compilar uma DLL)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DLL  
```  
  
## Comentários  
 A opção \/DLL cria uma DLL como o arquivo de saída principal.  UMA DLL normalmente contém as exporta que podem ser usadas por outro programa.  Há três métodos para especificar a exportações, listados na ordem recomendado para uso:  
  
1.  [\_\_declspec \(dllexport\)](../../cpp/dllexport-dllimport.md) no código\-fonte  
  
2.  Uma instrução de [EXPORTAÇÕES](../Topic/EXPORTS.md) em um arquivo .def  
  
3.  Uma especificação de [\/EXPORT](../../build/reference/export-exports-a-function.md) em um comando de LINK  
  
 Um programa pode usar mais de um método.  
  
 Outra maneira de criar uma DLL é com a instrução do definição de **BIBLIOTECA** .  As opções de \/BASE e \/DLL em conjunto são equivalentes à instrução de **BIBLIOTECA** .  
  
 Não especifique essa opção no ambiente de desenvolvimento; essa opção é para uso apenas na linha de comando.  Essa opção é definida quando você cria um projeto da DLL com um assistente do aplicativo.  
  
 Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar seu .dll, você deve transmitir o mesmo conjunto de arquivos de objeto ao criar o .dll, como é passada para criar a biblioteca de importação.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta de **Propriedades de Configuração** .  
  
3.  Clique na página de propriedades de **Geral** .  
  
4.  Modifique a propriedade de **Tipo de Configuração** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCPropertySheet.ConfigurationType%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)