---
title: Estrutura CDaoIndexInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoIndexInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), Indexes collection
- CDaoIndexInfo structure
ms.assetid: 251d8285-78ce-4716-a0b3-ccc3395fc437
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 92206d8d8f9b2315fb859e2712a83d32a4c293ad
ms.lasthandoff: 02/25/2017

---
# <a name="cdaoindexinfo-structure"></a>Estrutura CDaoIndexInfo
O `CDaoIndexInfo` estrutura contém informações sobre um objeto de índice definida para objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CDaoIndexInfo {  
    CDaoIndexInfo();
*// Constructor  
    CString m_strName;  // Primary  
    CDaoIndexFieldInfo* m_pFieldInfos;  // Primary  
    short m_nFields;    // Primary  
    BOOL m_bPrimary;    // Secondary  
    BOOL m_bUnique;     // Secondary  
    BOOL m_bClustered;  // Secondary  
    BOOL m_bIgnoreNulls;                // Secondary  
    BOOL m_bRequired;   // Secondary  
    BOOL m_bForeign;    // Secondary  
    long m_lDistinctCount;              // All  
 *// Below the // Implementation comment: *// Destructor, not otherwise documented  
};   
```  
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 Nomes de objeto field exclusivamente. Para obter detalhes, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
 `m_pFieldInfos`  
 Um ponteiro para uma matriz de [CDaoIndexFieldInfo](../../mfc/reference/cdaoindexfieldinfo-structure.md) objetos que indica quais campos tabledef ou conjunto de registros são campos-chave em um índice. Cada objeto identifica um campo no índice. A ordem de índice padrão é crescente. Um objeto de índice pode ter um ou mais campos que representam chaves de índice para cada registro. Eles podem ser crescente, decrescente, ou uma combinação.  
  
 `m_nFields`  
 O número de campos armazenados em `m_pFieldInfos`.  
  
 *m_bPrimary*  
 Se a propriedade primária é **TRUE**, o objeto de índice representa um índice primário. Um índice primário consiste em um ou mais campos que identificam com exclusividade todos os registros em uma tabela em uma ordem predefinida. Como o campo de índice deve ser exclusivo, a propriedade do objeto de índice exclusivo também é definida como **TRUE** em DAO. Se o índice primário consistir em mais de um campo, cada campo pode conter valores duplicados, mas cada combinação de valores de todos os campos indexados deve ser exclusiva. Um índice primário consiste em uma chave para a tabela e geralmente contém os mesmos campos de chave primária.  
  
 Quando você definir uma chave primária para uma tabela, a chave primária é automaticamente definida como o índice primário para a tabela. Para obter mais informações, consulte os tópicos "Propriedade primário" e "Propriedade exclusiva" na Ajuda do DAO.  
  
> [!NOTE]
>  Pode haver, no máximo, um índice primário em uma tabela.  
  
 *m_bUnique*  
 Indica se um objeto de índice representa um índice exclusivo para uma tabela. Se essa propriedade for **TRUE**, o objeto de índice representa um índice exclusivo. Um índice exclusivo consiste em um ou mais campos que organizam logicamente todos os registros em uma tabela em uma ordem exclusiva e predefinida. Se o índice consiste em um campo, os valores nesse campo devem ser exclusivos para a tabela inteira. Se o índice consiste em mais de um campo, cada campo pode conter valores duplicados, mas cada combinação de valores de todos os campos indexados deve ser exclusiva.  
  
 Se o primário e Unique propriedades de um objeto de índice são definidas como **TRUE**, o índice será exclusivo e primário: ele identifica exclusivamente todos os registros na tabela em uma ordem lógica predefinida. Se a propriedade principal é definida como **FALSE**, o índice é um índice secundário. Índices secundários (chave e não chave) organizam logicamente os registros em uma ordem predefinida sem servir como um identificador para os registros na tabela.  
  
 Para obter mais informações, consulte os tópicos "Propriedade primário" e "Propriedade exclusiva" na Ajuda do DAO.  
  
 *m_bClustered*  
 Indica se um objeto de índice representa um índice clusterizado para uma tabela. Se essa propriedade for **TRUE**, o objeto de índice representa um índice clusterizado; caso contrário, não. Um índice clusterizado consiste em uma ou mais não sejam chaves campos que, juntas, organizam todos os registros em uma tabela em uma ordem predefinida. Com um índice clusterizado, os dados na tabela literalmente são armazenados na ordem especificada pelo índice clusterizado. Um índice agrupado fornece acesso eficiente aos registros em uma tabela. Para obter mais informações, consulte o tópico "Propriedade Clustered" na Ajuda do DAO.  
  
> [!NOTE]
>  A propriedade Clustered é ignorada para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet porque o mecanismo de banco de dados Jet não oferece suporte a índices clusterizados.  
  
 *m_bIgnoreNulls*  
 Indica se há entradas de índice para os registros que têm valores nulos em seus campos de índice. Se essa propriedade for **TRUE**, campos com valores nulos não tem uma entrada de índice. Para tornar a busca por registros usando um campo mais rapidamente, você pode definir um índice para o campo. Se você permitir entradas Null em um campo indexado e espera que muitas das entradas NULL, você pode definir a propriedade do objeto index para ignorar **TRUE** para reduzir a quantidade de espaço de armazenamento que o índice usa. A configuração da propriedade ignorar e a configuração de propriedade necessário juntas determinam se um registro com um valor de índice de Null tem uma entrada de índice, como mostra a tabela a seguir.  
  
|Ignorar|Necessária|Nulo no campo de índice|  
|-----------------|--------------|-------------------------|  
|verdadeiro|False|Valor nulo permitido; Nenhuma entrada de índice adicionada.|  
|False|False|Valor nulo permitido; entrada de é adicionada.|  
|VERDADEIRO ou falso|verdadeiro|Valor nulo não permitido; Nenhuma entrada de índice adicionada.|  
  
 Para obter mais informações, consulte o tópico "Propriedade ignorar" na Ajuda do DAO.  
  
 `m_bRequired`  
 Indica se um objeto de índice DAO requer um valor não nulo. Se essa propriedade for **TRUE**, o objeto de índice não permite que um valor nulo. Para obter mais informações, consulte o tópico "Propriedade necessária" na Ajuda do DAO.  
  
> [!TIP]
>  Quando você pode definir essa propriedade para um objeto de índice DAO ou um objeto de campo (contido por um objeto de querydef, tabledef ou conjunto de registros), defina-o para o objeto de campo. A validade da configuração da propriedade de um objeto de campo é verificada antes que um objeto de índice.  
  
 *m_bForeign*  
 Indica se um objeto de índice representa uma chave estrangeira em uma tabela. Se essa propriedade for **TRUE**, o índice representa uma chave estrangeira em uma tabela. Uma chave estrangeira consiste em um ou mais campos em uma tabela externa que identificam exclusivamente uma linha em uma tabela primária. O mecanismo de banco de dados Microsoft Jet cria um objeto de índice para a tabela externa e define a propriedade externa quando você cria um relacionamento que impõe a integridade referencial. Para obter mais informações, consulte o tópico "Propriedade externa" na Ajuda do DAO.  
  
 *m_lDistinctCount*  
 Indica o número de valores exclusivos para o objeto de índice que estão incluídos na tabela associada. Verifique a propriedade DistinctCount para determinar o número de valores exclusivos, ou chaves, em um índice. Qualquer chave é contado apenas uma vez, mesmo que haja várias ocorrências desse valor se o índice permite valores duplicados. Essa informação é útil em aplicativos que tentam otimizar o acesso a dados avaliando as informações de índice. O número de valores exclusivos é também conhecido como a cardinalidade de um objeto de índice. A propriedade DistinctCount não sempre refletirá o número real de chaves em um momento específico. Por exemplo, uma alteração causada por uma reversão de transação não será refletida imediatamente na propriedade DistinctCount. Para obter mais informações, consulte o tópico "Propriedade DistinctCount" na Ajuda do DAO.  
  
## <a name="remarks"></a>Comentários  
 As referências ao primário, secundário e todos acima indicam como as informações são retornadas pelo `GetIndexInfo` a função de membro em classes [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getindexinfo) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getindexinfo).  
  
 Objetos de índice não são representados por uma classe do MFC. Em vez disso, DAO objetos objetos MFC subjacentes da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) contém uma coleção de objetos de índice, chamado de coleção de índices. Essas classes fornecem funções de membro para acessar itens individuais de informações de índice, ou você pode acessá-los todos de uma vez com um `CDaoIndexInfo` objeto chamando o `GetIndexInfo` a função de membro do objeto recipiente.  
  
 `CDaoIndexInfo`tem um construtor e um destruidor para corretamente aloque e desaloque as informações de campo de índice em `m_pFieldInfos`.  
  
 As informações recuperadas pelo `GetIndexInfo` a função de membro de um objeto tabledef é armazenada em um `CDaoIndexInfo` estrutura. Chamar o `GetIndexInfo` a função de membro do objeto tabledef contendo cuja coleção de índices o objeto de índice está armazenado. `CDaoIndexInfo`também define um `Dump` compilações de função de membro no modo de depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoIndexInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDaoTableDef::GetIndexInfo](../../mfc/reference/cdaotabledef-class.md#getindexinfo)


