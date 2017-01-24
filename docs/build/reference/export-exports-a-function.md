---
title: "/EXPORT (exporta uma fun&#231;&#227;o) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.ExportFunctions"
  - "/export"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /EXPORT"
  - "opção de vinculador EXPORT"
  - "opção de vinculador -EXPORT"
ms.assetid: 0920fb44-a472-4091-a8e6-73051f494ca0
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /EXPORT (exporta uma fun&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/EXPORT:entryname[,@ordinal[,NONAME]][,DATA]  
```  
  
## Comentários  
 Com essa opção, você pode exportar uma função do programa de forma que outros programas podem chamar a função.  Você também pode exportar dados.  Exporta as são normalmente definidas em uma DLL.  
  
 *O entryname* é o nome do item da função ou de dados como deve ser usada pelo programa de chamada.  `ordinal` especifica um índice na tabela de exportações no intervalo de 1 a 65.535; se você não especificar `ordinal`, o LINK atribui um.  A palavra\-chave de **NONAME** exporta a função apenas como um ordinal, sem *um entryname*.  
  
 A palavra\-chave de **DADOS** especifica que o item é exportado um item de dados.  O item de dados no programa cliente deve ser declarado usando **extern \_\_declspec\(dllimport\)**.  
  
 Há três métodos para exportar uma definição, listados na ordem recomendado para uso:  
  
1.  [\_\_declspec \(dllexport\)](../../cpp/dllexport-dllimport.md) no código\-fonte  
  
2.  Uma instrução de [EXPORTAÇÕES](../Topic/EXPORTS.md) em um arquivo .def  
  
3.  Uma especificação de \/EXPORT em um comando de LINK  
  
 Todos os três métodos podem ser usados no mesmo programa.  Quando o LINK cria um programa que contém a exportações, o também cria uma biblioteca de importação, a menos que um arquivo de .exp é usado na compilação.  
  
 O LINK decoraram formas de identificadores.  O compilador decora um identificador quando cria o arquivo de .obj.  Se *o entryname* está especificado ao vinculador em sua forma como ele aparece em undecorated \(origem\), o LINK tenta corresponder ao nome.  Se o não conseguir localizar uma correspondência exclusivo, o LINK emite uma mensagem de erro.  Use a ferramenta de [DUMPBIN](../../build/reference/dumpbin-reference.md) para obter o formulário de [nomes decorados](../Topic/Decorated%20Names.md) de um identificador do quando precisar de especifique ao vinculador.  
  
> [!NOTE]
>  Não especifique o formulário decorado de identificadores de C que 2.0 são declarados `__cdecl` ou `__stdcall`.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa de **Opções Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)