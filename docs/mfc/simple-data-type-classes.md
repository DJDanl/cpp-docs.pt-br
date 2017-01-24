---
title: "Classes de tipo de dados simples | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.data"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de dados [C++]"
  - "classes escalares [C++]"
  - "classes de tipo de dados simples"
ms.assetid: 0d591d68-0a33-49e9-8a6d-90c90de5c16a
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de tipo de dados simples
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes classes encapsulam coordenadas de desenho, cadeias de caracteres, e informações de hora e data, permitindo o uso prático de sintaxe C\+\+.  Esses objetos são amplamente usados como parâmetros para as funções de membro de classes do windows na biblioteca da classe.  Como `CPoint`, `CSize`, e `CRect` correspondem a **POINT**, a **TAMANHO**, e estruturas de `RECT` , respectivamente, em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)], você pode usar objetos dessas classes C\+\+ sempre que você pode usar essas estruturas de C \- idioma.  As classes fornecem interfaces úteis com suas funções de membro.  `CStringT` fornece cadeias de caracteres muito flexíveis dinâmicos.  `CTime`, `COleDateTime`, `CTimeSpan`, e **COleTimeSpan** representam valores de hora e data.  Para obter mais informações sobre essas classes, consulte o artigo [Data e hora](../atl-mfc-shared/date-and-time.md).  
  
 As classes que começam com “**COle**” são encapsulamento dos tipos de dados fornecidos pelo OLE.  Esses tipos de dados podem ser usados em programas do windows independentemente de outros recursos OLE forem usados.  
  
 [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md)  
 Contém cadeias de caracteres.  
  
 [CTime](../Topic/CTime%20Class.md)  
 Mantém valores absolutos de hora e data.  
  
 [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)  
 Wrapper do tipo **DATA**de automação OLE.  Representa a data e hora.  
  
 [CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md)  
 Mantém valores relacionados de hora e data.  
  
 [COleDateTimeSpan](../Topic/COleDateTimeSpan%20Class.md)  
 Mantém valores de `COleDateTime` de relativa, como a diferença entre dois valores de `COleDateTime` .  
  
 [CPoint](../Topic/CPoint%20Class.md)  
 As propriedades coordenam \(x, y\) par.  
  
 [CSize](../atl-mfc-shared/reference/csize-class.md)  
 As propriedades afastam\-se, posições relativas valores, ou emparelhados.  
  
 [CRect](../atl-mfc-shared/reference/crect-class.md)  
 Coordenadas das propriedades de áreas retangulares.  
  
 [CImageList](../Topic/CImageList%20Class.md)  
 Fornece a funcionalidade da lista da imagem do windows.  As listas de imagem são usadas com controles da lista e controles da árvore.  Também podem ser usados para armazenar e arquivar um conjunto de bitmaps mesmo feito sob medida.  
  
 [COleVariant](../mfc/reference/colevariant-class.md)  
 Wrapper do tipo **VARIANT**de automação OLE.  Os dados em **VARIANT**s podem ser armazenados em diversos formatos.  
  
 [COleCurrency](../Topic/COleCurrency%20Class.md)  
 Wrapper do tipo OLE **CURRENCY**de automação, um tipo aritmética de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos em seguida.  
  
> [!NOTE]
>  A partir do Visual C\+\+ .NET, `CRect`, `CSize`, e `CPoint` foram modificados para serem úteis em aplicativos de ATL ou de MFC.  Além disso, `CStringT` foi adicionado para fornecer `CString`MFC\- independente \- como a classe.  Para obter mais informações sobre as classes de utilitário compartilhadas, consulte [Classes compartilhadas](../atl-mfc-shared/atl-mfc-shared-classes.md).  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)