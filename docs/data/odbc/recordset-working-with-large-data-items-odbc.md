---
title: 'Conjunto de registros: Trabalhando com itens de dados grandes (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- BLOB (binary large object), recordsets
- ODBC recordsets, binary large objects
- recordsets, binary large objects
- binary large objects
- CLongBinary class, using in recordsets
ms.assetid: 3e80b5a8-b6e7-43c6-a816-e54befc513a3
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7ad1ba9120575840ac833a20061b3e1c5a547412
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="recordset-working-with-large-data-items-odbc"></a>Conjunto de registros: trabalhando com itens de dados grandes (ODBC)
Este tópico se aplica as classes MFC ODBC e as classes DAO MFC.  
  
> [!NOTE]
>  Se você estiver usando as classes DAO MFC, gerenciar os itens de dados grandes com a classe [CByteArray](../../mfc/reference/cbytearray-class.md) em vez da classe [CLongBinary](../../mfc/reference/clongbinary-class.md). Se você estiver usando as classes MFC ODBC com busca de linhas em massa, use `CLongBinary` em vez de `CByteArray`. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Suponha que seu banco de dados pode armazenar grandes pedaços de dados, como bitmaps (fotografias de funcionário, mapas, imagens de produtos, objetos OLE e assim por diante). Esse tipo de dados é conhecido como um objeto binário grande (ou BLOB) porque:  
  
-   Cada valor de campo é grande.  
  
-   Ao contrário dos números e outros tipos de dados simples, ele tem tamanho não previsível.  
  
-   Os dados são formless da perspectiva do seu programa.  
  
 Este tópico explica o suporte as classes de banco de dados fornecem para trabalhar com esses objetos.  
  
##  <a name="_core_managing_large_objects"></a>Gerenciando objetos grandes  
 Conjuntos de registros tem duas formas de resolver especial dificuldade de gerenciar objetos binários grandes. Você pode usar a classe [CByteArray](../../mfc/reference/cbytearray-class.md) ou você pode usar a classe [CLongBinary](../../mfc/reference/clongbinary-class.md). Em geral, `CByteArray` é a melhor maneira de gerenciar dados binários longos.  
  
 `CByteArray`requer mais sobrecarga do que `CLongBinary` , mas é mais compatível com, conforme descrito em [a classe CByteArray](#_core_the_cbytearray_class). `CLongBinary`é descrito brevemente na [a classe CLongBinary](#_core_the_clongbinary_class).  
  
 Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com itens de dados grandes, consulte [45 de observação técnica](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).  
  
##  <a name="_core_the_cbytearray_class"></a>Classe CByteArray  
 `CByteArray`é uma das classes de coleção MFC. Um `CByteArray` objeto armazena uma matriz de bytes de dinâmica — a matriz pode crescer, se necessário. A classe fornece acesso rápido por índice, assim como acontece com matrizes de C++ internos. `CByteArray`objetos podem ser serializados e despejados para fins de diagnóstico. A classe fornece funções de membro para obter e definir os bytes especificados, inserindo e anexando bytes e remoção de um byte ou todos os bytes. Essas instalações fazer análise de dados binários. Por exemplo, se o objeto binário é um objeto OLE, você talvez precise trabalhar com alguns bytes de cabeçalho para acessar o objeto real.  
  
##  <a name="_core_using_cbytearray_in_recordsets"></a>Usando CByteArray em conjuntos de registros  
 Fornecendo um membro de dados do campo de seu conjunto de registros do tipo `CByteArray`, fornecer uma base fixa do qual [RFX](../../data/odbc/record-field-exchange-rfx.md) pode gerenciar a transferência de tal objeto entre o conjunto de registros e a fonte de dados e por meio do qual você pode manipular o dados dentro do objeto. RFX precisa de um site específico para dados recuperados e você precisa de uma maneira de acessar os dados subjacentes.  
  
 Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com itens de dados grandes, consulte [45 de observação técnica](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).  
  
##  <a name="_core_the_clongbinary_class"></a>Classe CLongBinary  
 Um [CLongBinary](../../mfc/reference/clongbinary-class.md) objeto é um shell simple em torno de um `HGLOBAL` identificador para um bloco de armazenamento alocado no heap. Quando ele associa uma coluna de tabela que contém um objeto binário grande, RFX aloca o `HGLOBAL` tratar quando ele precisa transferir os dados para o conjunto de registros e armazena o identificador no `CLongBinary` campo do conjunto de registros.  
  
 Por sua vez, você usa o `HGLOBAL` tratar, `m_hData`, para trabalhar com os dados em si, operar nele, como você faria em qualquer manipular dados. Isso é onde [CByteArray](../../mfc/reference/cbytearray-class.md) adiciona recursos.  
  
> [!CAUTION]
>  Objetos de CLongBinary não podem ser usados como parâmetros em chamadas de função. Além disso, sua implementação, que chama **:: SQLGetData**, necessariamente reduz o desempenho de rolagem para um instantâneo rolável. Isso também pode ser verdadeiro quando você usar um **:: SQLGetData** chamada para recuperar colunas de esquema dinâmico.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)   
 [RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)