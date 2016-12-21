---
title: "Classe de CPathT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL.CPathT"
  - "CPathT"
  - "ATL::CPathT<StringType>"
  - "ATL::CPathT"
  - "ATL.CPathT<StringType>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPathT"
ms.assetid: eba4137d-1fd2-4b44-a2e1-0944db64df3c
caps.latest.revision: 20
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPathT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa um caminho.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template< typename   
      StringType  
      >   
class CPathT  
```  
  
#### Parâmetros  
 `StringType`  
 A classe de cadeia de caracteres de ATL\/MFC a ser usado para o caminho \(consulte [CStringT](../../atl-mfc-shared/reference/cstringt-class.md)\).  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPathT::PCXSTR](../Topic/CPathT::PCXSTR.md)|Um tipo constante de cadeia de caracteres.|  
|[CPathT::PXSTR](../Topic/CPathT::PXSTR.md)|Um tipo cadeia de caracteres.|  
|[CPathT::XCHAR](../Topic/CPathT::XCHAR.md)|Um tipo de caracteres.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPathT::CPathT](../Topic/CPathT::CPathT.md)|o construtor para o caminho.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPathT::AddBackslash](../Topic/CPathT::AddBackslash.md)|Chamar este método para adicionar uma barra invertida ao final de uma cadeia de caracteres para criar a sintaxe correta para um caminho.|  
|[CPathT::AddExtension](../Topic/CPathT::AddExtension.md)|Chamar este método para adicionar uma extensão de arquivo a um caminho.|  
|[CPathT::Append](../Topic/CPathT::Append.md)|Chamar esse método para acrescentar uma cadeia de caracteres para o caminho atual.|  
|[CPathT::BuildRoot](../Topic/CPathT::BuildRoot.md)|Chamar esse método para criar um caminho raiz de um número determinado de unidade.|  
|[CPathT::Canonicalize](../Topic/CPathT::Canonicalize.md)|Chamar esse método para converter o caminho para a forma canônica.|  
|[CPathT::Combine](../Topic/CPathT::Combine.md)|Chamar esse método para concatenar uma cadeia de caracteres que representam um nome de diretório e uma cadeia de caracteres que representa um nome de caminho de arquivo em um caminho.|  
|[CPathT::CommonPrefix](../Topic/CPathT::CommonPrefix.md)|Chamar esse método para determinar se o caminho especificado compartilhar um prefixo comum com o caminho atual.|  
|[CPathT::CompactPath](../Topic/CPathT::CompactPath.md)|Chamar esse método para truncar um caminho de arquivo para caber em uma determinada largura de pixel substituindo componentes do caminho com as elipses.|  
|[CPathT::CompactPathEx](../Topic/CPathT::CompactPathEx.md)|Chamar esse método para truncar um caminho de arquivo para caber em um determinado número de caracteres substituindo componentes do caminho com as elipses.|  
|[CPathT::FileExists](../Topic/CPathT::FileExists.md)|Chamar esse método para verificar se o arquivo no nome do caminho existe.|  
|[CPathT::FindExtension](../Topic/CPathT::FindExtension.md)|Chamar esse método para encontrar a posição de extensão de arquivo no caminho.|  
|[CPathT::FindFileName](../Topic/CPathT::FindFileName.md)|Chamar esse método para encontrar a posição de nome de arquivo no caminho.|  
|[CPathT::GetDriveNumber](../Topic/CPathT::GetDriveNumber.md)|Chamar esse método para procurar o caminho por uma letra da unidade dentro do intervalo de “A” a “Z” e retornar o número de unidade correspondente.|  
|[CPathT::GetExtension](../Topic/CPathT::GetExtension.md)|Chamar esse método para obter a extensão de arquivo do caminho.|  
|[CPathT::IsDirectory](../Topic/CPathT::IsDirectory.md)|Chamar esse método para verificar se o caminho é um diretório válido.|  
|[CPathT::IsFileSpec](../Topic/CPathT::IsFileSpec.md)|Chamar esse método para procurar um caminho por todos os caracteres de restrição \(por exemplo, “:” ou “\\"\).  Se não houver nenhum caractere de restrição atual, o caminho é considerado ser um caminho de Arquivo. especs de.|  
|[CPathT::IsPrefix](../Topic/CPathT::IsPrefix.md)|Chamar esse método para determinar se um caminho contém um prefixo válida de tipo passado por `pszPrefix`.|  
|[CPathT::IsRelative](../Topic/CPathT::IsRelative.md)|Chamar esse método para determinar se o caminho é relativo.|  
|[CPathT::IsRoot](../Topic/CPathT::IsRoot.md)|Chamar esse método para determinar se o caminho é uma raiz da pasta.|  
|[CPathT::IsSameRoot](../Topic/CPathT::IsSameRoot.md)|Chamar esse método para determinar se outro caminho tem um componente raiz comuns com o caminho atual.|  
|[CPathT::IsUNC](../Topic/CPathT::IsUNC.md)|Chamar esse método para determinar se o caminho é válido de um caminho UNC \(convenção de nomenclatura universal\) para um servidor e um compartilhamento.|  
|[CPathT::IsUNCServer](../Topic/CPathT::IsUNCServer.md)|Chamar esse método para determinar se o caminho é válido de um caminho UNC \(convenção de nomenclatura universal\) para um servidor somente.|  
|[CPathT::IsUNCServerShare](../Topic/CPathT::IsUNCServerShare.md)|Chamar esse método para determinar se o caminho é um caminho válido do compartilhamento UNC \(convenção de nomenclatura universal\), \\\\*servidor*\\*compartilhamento*.|  
|[CPathT::MakePretty](../Topic/CPathT::MakePretty.md)|Chamar esse método para converter um caminho para todos os caracteres minúsculos para dar ao caminho uma aparência consistente.|  
|[CPathT::MatchSpec](../Topic/CPathT::MatchSpec.md)|Chamar esse método para procurar o caminho por uma cadeia de caracteres que contém um tipo de correspondência de curinga.|  
|[CPathT::QuoteSpaces](../Topic/CPathT::QuoteSpaces.md)|Chamar esse método para incluir o caminho entre aspas se os contém quaisquer espaços.|  
|[CPathT::RelativePathTo](../Topic/CPathT::RelativePathTo.md)|Chamar esse método para criar um caminho relativo de um arquivo ou pasta para outra.|  
|[CPathT::RemoveArgs](../Topic/CPathT::RemoveArgs.md)|Chamar esse método para remover todos os argumentos de linha de comando do caminho.|  
|[CPathT::RemoveBackslash](../Topic/CPathT::RemoveBackslash.md)|Chamar esse método para remover a barra invertida à direita do caminho.|  
|[CPathT::RemoveBlanks](../Topic/CPathT::RemoveBlanks.md)|Chamar esse método para remover qualquer o primeiro e espaço à direita do caminho.|  
|[CPathT::RemoveExtension](../Topic/CPathT::RemoveExtension.md)|Chamar esse método para remover a extensão de arquivo do caminho, se houver um.|  
|[CPathT::RemoveFileSpec](../Topic/CPathT::RemoveFileSpec.md)|Chamar esse método para remover o nome de arquivo e a barra invertida à direita do caminho, se o tiver.|  
|[CPathT::RenameExtension](../Topic/CPathT::RenameExtension.md)|Chamar esse método para substituir a extensão de nome de arquivo no caminho com uma nova extensão.  Se o nome de arquivo não contém uma extensão, a extensão será anexado ao final da cadeia de caracteres.|  
|[CPathT::SkipRoot](../Topic/CPathT::SkipRoot.md)|Chamar esse método para analisar um caminho, ignorando a letra da unidade ou o servidor de compartilhamento UNC\/de partes do caminho.|  
|[CPathT::StripPath](../Topic/CPathT::StripPath.md)|Chamar esse método para remover a parte do caminho de um caminho totalmente qualificado e um nome de arquivo.|  
|[CPathT::StripToRoot](../Topic/CPathT::StripToRoot.md)|Chamar esse método para remover todas as partes do caminho para a exceção de informações da raiz.|  
|[CPathT::UnquoteSpaces](../Topic/CPathT::UnquoteSpaces.md)|Chamar esse método para remover do início a aspas e final de um caminho.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Const StringType de CPathT::operator &](../Topic/CPathT::operator%20const%20StringType%20&.md)|Este operador permite que o objeto é tratado como uma cadeia de caracteres.|  
|[CPathT::operator CPathT::PCXSTR](../Topic/CPathT::operator%20CPathT::PCXSTR.md)|Este operador permite que o objeto é tratado como uma cadeia de caracteres.|  
|[CPathT::operator StringType &](../Topic/CPathT::operator%20StringType%20&.md)|Este operador permite que o objeto é tratado como uma cadeia de caracteres.|  
|[CPathT::operator \+\=](../Topic/CPathT::operator%20+=.md)|Este operador acrescenta uma cadeia de caracteres para o caminho.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPathT::m\_strPath](../Topic/CPathT::m_strPath.md)|o caminho.|  
  
## Comentários  
 `CPath`, `CPathA`, e `CPathW` instanciações de `CPathT` são definidos como segue:  
  
 `typedef CPathT< CString > CPath;`  
  
 `typedef CPathT< CStringA > CPathA;`  
  
 `typedef CPathT< CStringW > CPathW;`  
  
## Requisitos  
 **Cabeçalho:** atlpath.h  
  
## Consulte também  
 [Classes](../../atl/reference/atl-classes.md)   
 [Classe de CStringT](../../atl-mfc-shared/reference/cstringt-class.md)