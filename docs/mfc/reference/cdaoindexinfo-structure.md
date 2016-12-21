---
title: "Estrutura CDaoIndexInfo | Microsoft Docs"
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
  - "CDaoIndexInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CDaoIndexInfo"
  - "DAO (Objetos de Acesso a Dados), Coleção de índices"
ms.assetid: 251d8285-78ce-4716-a0b3-ccc3395fc437
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CDaoIndexInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CDaoIndexInfo` contém informações sobre um objeto de índice definido para objetos \(DAO\) de acesso a dados.  
  
## Sintaxe  
  
```  
  
      struct CDaoIndexInfo {  
   CDaoIndexInfo( );                   // Constructor  
   CString m_strName;                  // Primary  
   CDaoIndexFieldInfo* m_pFieldInfos;  // Primary  
   short m_nFields;                    // Primary  
   BOOL m_bPrimary;                    // Secondary  
   BOOL m_bUnique;                     // Secondary  
   BOOL m_bClustered;                  // Secondary  
   BOOL m_bIgnoreNulls;                // Secondary  
   BOOL m_bRequired;                   // Secondary  
   BOOL m_bForeign;                    // Secondary  
   long m_lDistinctCount;              // All  
  
   // Below the // Implementation comment:  
   // Destructor, not otherwise documented  
};   
```  
  
#### Parâmetros  
 `m_strName`  
 Nomear exclusivamente o objeto do campo.  Para obter detalhes, consulte o tópico “propriedade nome” na ajuda de DAO.  
  
 `m_pFieldInfos`  
 Um ponteiro para uma matriz de objetos [CDaoIndexFieldInfo](../Topic/CDaoIndexFieldInfo%20Structure.md) indicando quais campos de tabledef ou conjunto de registros são campo de chave em um índice.  Cada objeto identifica um campo no índice.  A ordem padrão de índice é crescente.  Um objeto de índice pode ter um ou mais campos que representam chaves de índice para cada registro.  Eles podem ser do crescent, em ordem decrescente, ou uma combinação.  
  
 `m_nFields`  
 O número de campos armazenados em `m_pFieldInfos`.  
  
 *m\_bPrimary*  
 Se a propriedade é **Verdadeiro**primário, o objeto de índice representa um índice primário.  Um índice primário consiste em um ou mais campos que identificam exclusivamente todos os registros em uma tabela em uma ordem predefinido.  Como o campo de índice deve ser exclusivo, a propriedade exclusiva do objeto de índice também está definida na **Verdadeiro** DAO.  Se o índice primário consistir em mais de um campo, cada campo pode conter valores duplicados, mas cada combinação de valores de todos os campos indexados deve ser exclusivo.  Um índice primário consiste em uma chave para a tabela e normalmente contém os mesmos campos que a chave primária.  
  
 Quando você definir uma chave primária para uma tabela, a chave primária é definido automaticamente como o índice primário para a tabela.  Para obter mais informações, consulte os tópicos “propriedade primário” e “propriedade exclusiva” na ajuda de DAO.  
  
> [!NOTE]
>  Pode haver, no máximo, um índice primário em uma tabela.  
  
 *m\_bUnique*  
 Indica se um objeto de índice representa um índice exclusivo para uma tabela.  Se essa propriedade for **Verdadeiro**, o objeto de índice representa um índice que seja exclusivo.  Um índice exclusivo consiste em um ou mais campos que organizam logicamente todos os registros em uma tabela em uma ordem exclusivo, predefinido.  Se o índice consiste em um campo, os valores nesse campo devem ser exclusivos para toda a tabela.  Se o índice consistir em mais de um campo, cada campo pode conter valores duplicados, mas cada combinação de valores de todos os campos indexados deve ser exclusivo.  
  
 Se as propriedades exclusivas e primários de um objeto de índice são definidas como **Verdadeiro**, o índice é exclusiva e primária: Identifica exclusivamente todos os registros da tabela em uma ordem predefinido, lógico.  Se a propriedade é definida como **Falso**primário, o índice for um índice secundário.  Os índices secundários \(combinação de chave e não chave\) organizam logicamente registros em uma ordem predefinido sem funcionar como um identificador para registros na tabela.  
  
 Para obter mais informações, consulte os tópicos “propriedade primário” e “propriedade exclusiva” na ajuda de DAO.  
  
 *m\_bClustered*  
 Indica se um objeto de índice representa um índice clusterizado para uma tabela.  Se essa propriedade for **Verdadeiro**, o objeto de índice representa um índice clusterizado; caso contrário, não.  Um índice clusterizado consiste em um ou mais campos que não chave, que juntas, organizam todos os registros em uma tabela em uma ordem predefinido.  Com um índice clusterizado, os dados da tabela são armazenados literal na ordem especificada pelo índice clusterizado.  Um índice clusterizado fornece acesso eficiente dos registros em uma tabela.  Para obter mais informações, consulte o tópico “agrupados da propriedade” na ajuda de DAO.  
  
> [!NOTE]
>  A propriedade clustered é ignorada para as bases de dados que usam o mecanismo de base de dados do Microsoft Jet porque o mecanismo de base de dados Jet não oferece suporte a índices clusterizados.  
  
 *m\_bIgnoreNulls*  
 Indica se houver entradas de índice para os registros que têm valores nulos em seus campos de índice.  Se essa propriedade for **Verdadeiro**, os campos com valores nulos não têm uma entrada de índice.  Para fazer a pesquisa por registros usando um campo mais rapidamente, você pode definir um índice do campo.  Se você permitir entradas nulas em um campo indexado e em espera muitas das entradas ser nulas, você pode definir a propriedade de IgnoreNulls para o objeto de índice a **Verdadeiro** para reduzir a quantidade de espaço de armazenamento que usa o índice.  A configuração de propriedade de IgnoreNulls e a configuração de propriedade exigida junto determinam se um registro com um valor nulo de índice tem uma entrada de índice, pois a tabela a seguir mostra.  
  
|IgnoreNulls|Obrigatório|Zero no campo de índice|  
|-----------------|-----------------|-----------------------------|  
|True|False|Valor nulo permitido; nenhuma entrada de índice adicionada.|  
|False|False|Valor nulo permitido; entrada de índice adicionada.|  
|Verdadeiro ou falso|True|Valor nulo não permitido; nenhuma entrada de índice adicionada.|  
  
 Para obter mais informações, consulte o tópico “propriedade IgnoreNulls” na ajuda de DAO.  
  
 `m_bRequired`  
 Indica se um objeto de índice de DAO requer um valor não nulo.  Se essa propriedade for **Verdadeiro**, o objeto de índice não permitir um valor nulo.  Para obter mais informações, consulte o tópico “necessário para a propriedade” na ajuda de DAO.  
  
> [!TIP]
>  Quando você pode definir esta propriedade para um objeto de índice de DAO ou um objeto do campo \(contido por um tabledef, por um conjunto de registros, ou por um objeto de querydef\), defina\-o para o objeto do campo.  A validade da configuração da propriedade de um objeto do campo é verificada antes de um objeto de índice.  
  
 *m\_bForeign*  
 Indica se um objeto de índice representa uma chave estrangeira em uma tabela.  Se essa propriedade for, o índice **Verdadeiro**representa uma chave estrangeira em uma tabela.  Uma chave estrangeira consiste em um ou mais campos em uma tabela estrangeira que identificam exclusivamente uma linha em uma tabela primária.  O mecanismo de base de dados do Microsoft Jet cria um objeto de índice para a tabela estrangeira e define a propriedade estrangeira quando você cria uma relação que têm integridade referencial.  Para obter mais informações, consulte o tópico “propriedade estrangeira” na ajuda de DAO.  
  
 *m\_lDistinctCount*  
 Indica o número de valores exclusivos para o objeto de índice que estão incluídos na tabela associada.  Verifique a propriedade de DistinctCount para determinar o número de valores exclusivos, ou chaves, em um índice.  Qualquer chave é contado apenas uma vez, mesmo que pode haver várias ocorrências desse valor se as licenças de índice encontrar valores duplicados.  Essas informações são úteis em aplicativos que tenta otimizar o acesso a dados para avaliar as informações de índice.  O número de valores exclusivos também é conhecido como a cardinalidade de um objeto de índice.  A propriedade de DistinctCount não refletirá sempre o número real de chaves em um determinado momento.  Por exemplo, uma mudança causada por uma reversão de transações não serão refletidas imediatamente na propriedade DistinctCount.  Para obter mais informações, consulte o tópico “propriedade DistinctCount” na ajuda de DAO.  
  
## Comentários  
 As referências à primário, secundário, e todas as anterior indicam como as informações são retornadas pela função de membro de `GetIndexInfo` nas classes [CDaoTableDef](../Topic/CDaoTableDef::GetIndexInfo.md) e [CDaoRecordset](../Topic/CDaoRecordset::GetIndexInfo.md).  
  
 Os objetos de índice não são representados por uma classe de MFC.  Em vez disso, os objetos de DAO que são a base de objetos MFC da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) contém uma coleção de objetos de índice, chamada a coleção de índices.  Essas classes fornecem funções de membro para acessar itens individuais de informações de índice, ou você pode acessar de uma vez com um objeto de `CDaoIndexInfo` chamando a função de membro de `GetIndexInfo` do objeto contentor.  
  
 `CDaoIndexInfo` tem um construtor e um destruidor para aloque e desaloque corretamente informações de campo de índice em `m_pFieldInfos`.  
  
 As informações recuperadas pela função de membro de `GetIndexInfo` de um objeto de tabledef são armazenadas em uma estrutura de `CDaoIndexInfo` .  Chame a função de membro de `GetIndexInfo` do objeto contentor de tabledef em cuja coleção de índices o objeto de índice está armazenado.  `CDaoIndexInfo` também define uma função de membro de `Dump` em construções de depuração.  Você pode usar para `Dump` despejar os conteúdos de um objeto de `CDaoIndexInfo` .  
  
## Requisitos  
 **Header:** afxdao.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDaoTableDef::GetIndexInfo](../Topic/CDaoTableDef::GetIndexInfo.md)