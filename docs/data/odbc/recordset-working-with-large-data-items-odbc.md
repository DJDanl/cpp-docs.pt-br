---
title: "Conjunto de registros: trabalhando com itens de dados grandes (ODBC) | Microsoft Docs"
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
  - "objetos binários grandes"
  - "BLOB (objeto binário grande), conjuntos de registros"
  - "Classe CLongBinary, usando em conjuntos de registros"
  - "conjunto de registros ODBC, objetos binários grandes"
  - "conjuntos de registros, objetos binários grandes"
ms.assetid: 3e80b5a8-b6e7-43c6-a816-e54befc513a3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: trabalhando com itens de dados grandes (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplicam às classes de MFC ODBC e às classes de MFC DAO.  
  
> [!NOTE]
>  Se você estiver usando as classes MFC DAO grandes, gerenciar seus itens de dados com a classe [CByteArray](../../mfc/reference/cbytearray-class.md) em vez de que classifica [CLongBinary](../../mfc/reference/clongbinary-class.md).  Se você estiver usando as classes MFC ODBC com a linha em massa que pesquisa, use `CLongBinary` em vez de `CByteArray`.  Para obter mais informações sobre a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Suponhamos que seu base de dados pode armazenar grandes blocos de dados, como bitmaps \(fotografias de funcionário, mapas, imagens de produto, objetos OLE, e assim por diante\).  Esse tipo de dados é frequentemente chamado de um objeto binário grande \(BLOB\) ou o como:  
  
-   Cada valor de campo for grande.  
  
-   Diferentemente dos números e outros tipos de dados simples, não tem nenhum tamanho previsível.  
  
-   Os dados são informes da perspectiva do programa.  
  
 Este tópico explica que oferece suporte às classes de base de dados fornecem trabalhando com esses objetos.  
  
##  <a name="_core_managing_large_objects"></a> Gerenciando objetos grandes  
 Os conjuntos de registros têm duas maneiras de resolver dificuldade especial de gerenciar objetos binários grandes\).  Você pode usar a classe [CByteArray](../../mfc/reference/cbytearray-class.md) ou você pode usar a classe [CLongBinary](../../mfc/reference/clongbinary-class.md).  Em geral, `CByteArray` é o modo preferido de gerenciar dados grandes binários.  
  
 `CByteArray` requer mais sobrecarga do que `CLongBinary` mas é mais capaz, conforme descrito em [A classe de CByteArray](#_core_the_cbytearray_class).  `CLongBinary` é descrita brevemente em [A classe de CLongBinary](#_core_the_clongbinary_class).  
  
 Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com grandes itens de dados, consulte [Observação 45 técnica](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).  
  
##  <a name="_core_the_cbytearray_class"></a> Classe de CByteArray  
 `CByteArray` é uma das classes de coleção de MFC.  Um objeto de `CByteArray` dinâmico armazena uma matriz de bytes — a matriz pode aumentar quando necessário.  A classe fornece acesso rápido por índice, como a matrizes internos C\+\+.  os objetos de`CByteArray` podem ser serializados e despejado para fins de diagnóstico.  As funções de membro de fontes da classe para obter e definir bytes especificados, inserir e anexar bytes, e o descarte de um byte ou todos os bytes.  Essas instalações facilitam a análise dos dados binários.  Por exemplo, se o objeto binário é um objeto OLE, você pode ter que trabalhar alguns bytes de cabeçalho para alcançar o objeto atual.  
  
##  <a name="_core_using_cbytearray_in_recordsets"></a> Usando CByteArray nos conjuntos de registros  
 Fornecendo a um membro de dados do campo do conjunto de registros o tipo `CByteArray`, você fornece uma base fixa que [RFX](../../data/odbc/record-field-exchange-rfx.md) pode gerenciar a transferência de um objeto entre o conjunto de registros e a fonte de dados e com os quais você pode manipular os dados no objeto.  RFX precisa de um site específica para dados recuperados, e você precisa de uma forma de acessar os dados subjacentes.  
  
 Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com grandes itens de dados, consulte [Observação 45 técnica](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).  
  
##  <a name="_core_the_clongbinary_class"></a> Classe de CLongBinary  
 Um objeto de [CLongBinary](../../mfc/reference/clongbinary-class.md) é um shell simples ao redor de um identificador de `HGLOBAL` em um bloco de armazenamento alocado no heap.  Quando associa uma coluna da tabela que contém um objeto binário grande\), RFX atribui a alça de `HGLOBAL` quando precisar transferir os dados ao conjunto de registros e armazena o identificador de `CLongBinary` no campo do conjunto de registros.  
  
 Por sua vez, você usa o identificador de `HGLOBAL` , `m_hData`, trabalhar com os dados propriamente ditos, operando nela como você faria em todos os dados do identificador.  É aí que [CByteArray](../../mfc/reference/cbytearray-class.md) adicionar recursos.  
  
> [!CAUTION]
>  Os objetos de CLongBinary não podem ser usados como parâmetros em chamadas de função.  Além disso, a sua implementação, que chama **::SQLGetData**necessariamente, velocidade do desempenho de rolagem para um instantâneo rolável.  Isso também pode ser verdadeiro quando você usa uma chamada de **::SQLGetData** você mesmo para recuperar colunas dinâmicas do esquema.  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: obtendo SUMs e outros resultados agregados \(ODBC\)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)   
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)