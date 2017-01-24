---
title: "Classe de CLongBinary | Microsoft Docs"
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
  - "BLOB"
  - "CLongBinary"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "BLOB (objeto grande binário)"
  - "BLOB (objeto grande binário), Classe de CLongBinary"
  - "Classe de CLongBinary"
ms.assetid: f4320059-aeb4-4ee5-bc2b-25f19d898ef5
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CLongBinary
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Simplifica trabalhar com objetos de dados binários muito grandes \(Soltar freqüentemente chamado, ou “objetos binários grandes”\) em um banco de dados.  
  
## Sintaxe  
  
```  
class CLongBinary : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLongBinary::CLongBinary](../Topic/CLongBinary::CLongBinary.md)|Constrói um objeto de `CLongBinary` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLongBinary::m\_dwDataLength](../Topic/CLongBinary::m_dwDataLength.md)|Contém o real tamanho em bytes do objeto de dados cuja identificador é armazenada em `m_hData`.|  
|[CLongBinary::m\_hData](../Topic/CLongBinary::m_hData.md)|Contém uma alça de `HGLOBAL` do windows para o objeto real da imagem.|  
  
## Comentários  
 Por exemplo, um campo do registro em uma tabela SQL pode conter um bitmap que representa uma imagem.  Um objeto de `CLongBinary` armazena um objeto e mantém registro do seu tamanho.  
  
> [!NOTE]
>  Geralmente, é melhor prática usar agora [CByteArray](../../mfc/reference/cbytearray-class.md) em conjunto com a função de [DFX\_Binary](../Topic/DFX_Binary.md) .  Você ainda pode usar `CLongBinary`, mas em geral `CByteArray` fornece mais funcionalidade no Win32, desde que não há um limite de tamanho encontrada com `CByteArray`de 16 bits.  Este conselhos programação se aplica a objetos com \(DAO\) de acesso a dados ODBC \(bem como ODBC\).  
  
 Para usar um objeto de `CLongBinary` , declare um membro de dados do campo de tipo `CLongBinary` em sua classe do conjunto de registros.  Esse membro será inserido um membro da classe do conjunto de registros e será construída quando o conjunto de registros é construído.  Depois que o objeto de `CLongBinary` é construído, o mecanismo de troca do campo do registro \(RFX\) carrega o objeto de dados de um campo no registro atual na fonte de dados e armazená\-lo de volta para o registro quando o registro é atualizado.  RFX consulta a fonte de dados para o tamanho do objeto binário grande, atribui o armazenamento para ele \(por meio do membro de dados de `m_hData` do objeto de `CLongBinary` \), e os armazenamentos uma alça de `HGLOBAL` a dados em `m_hData`.  RFX também armazena o tamanho real do objeto de dados no membro de dados de `m_dwDataLength` .  Trabalhar com dados no objeto com `m_hData`, usando as mesmas técnicas que você normalmente usariam para manipular os dados armazenados em uma alça de `HGLOBAL` do windows.  
  
 Quando você for o conjunto de registros, o objeto inserido de `CLongBinary` também é destruído, e o destrutor desaloca a alça de dados de `HGLOBAL` .  
  
 Para obter mais informações sobre objetos grandes e uso de `CLongBinary`, consulte os artigos [Recordset \(ODBC\)](../../data/odbc/recordset-odbc.md) e [conjunto de registros: Trabalhar com grandes itens de dados \(ODBC\)](../../data/odbc/recordset-working-with-large-data-items-odbc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CLongBinary`  
  
## Requisitos  
 **Cabeçalho:** afxdb\_.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)