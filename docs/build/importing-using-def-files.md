---
title: "Importando usando arquivos DEF | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .def [C++], importando com"
  - "arquivos def [C++], importando com"
  - "Atributo dllimport [C++], arquivos DEF"
  - "DLLs [C++], arquivos DEF"
  - "importando DLLs [C++], arquivos DEF"
ms.assetid: aefdbf50-f603-488a-b0d7-ed737bae311d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Importando usando arquivos DEF
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você optar por usar **\_\_declspec\(dllimport\)** junto com um arquivo .def, modifique o arquivo .def para usar ser incluída no lugar de CONSTANTE para reduzir a probabilidade da codificação incorreta causará um problema:  
  
```  
// project.def  
LIBRARY project  
EXPORTS  
   ulDataInDll   DATA  
```  
  
 A tabela a seguir mostra como.  
  
|Palavra\-Chave|Emite na biblioteca de importação|Exporta|  
|--------------------|---------------------------------------|-------------|  
|`CONSTANT`|`_imp_ulDataInDll_ulDataInDll`|`_ulDataInDll`|  
|`DATA`|`_imp_ulDataInDll`|`_ulDataInDll`|  
  
 Usando **\_\_declspec\(dllimport\)** e a lista CONSTANTE a versão de `imp` e o nome undecorated na biblioteca de importação da DLL de .lib que é criada para permitir vincular explícito.  Usando **\_\_declspec\(dllimport\)** e listas DATA apenas a versão de `imp` do nome.  
  
 Se você usar a CONSTANTE, qualquer uma das construções de código pode ser usada para acessar `ulDataInDll`:  
  
```  
__declspec(dllimport) ULONG ulDataInDll; /*prototype*/  
if (ulDataInDll == 0L)   /*sample code fragment*/  
```  
  
 \- ou \-  
  
```  
ULONG *ulDataInDll;      /*prototype*/  
if (*ulDataInDll == 0L)  /*sample code fragment*/  
```  
  
 No entanto, se você usar DATA no arquivo .def, somente o código compilado com a seguinte definição pode acessar `ulDataInDll`variável:  
  
```  
__declspec(dllimport) ULONG ulDataInDll;  
  
if (ulDataInDll == 0L)   /*sample code fragment*/  
```  
  
 Usar a CONSTANTE é mais arriscada pois se você esquecer usar o nível de nomes indiretos adicional, você poderia acessar o ponteiro de tabela de endereço de importação para a variável — não a variável próprio.  Esse tipo de problema pode frequentemente manifestar como uma violação de acesso como a tabela de endereço de importação é feita somente leitura no momento pelo compilador e pelo vinculador.  
  
 O vinculador atual do Visual C\+\+ emite um aviso se consulte a CONSTANTE no arquivo .def para considerar estas caixas.  O único motivo real usar a CONSTANTE se você não pode recompilar um arquivo de objeto onde o arquivo de cabeçalho não listados **\_\_declspec\(dllimport\)** no protótipo.  
  
## Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)