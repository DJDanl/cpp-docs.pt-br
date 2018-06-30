---
title: Estrutura CDaoIndexInfo | Microsoft Docs
ms.custom: ''
ms.date: 06/25/2018
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoIndexInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), Indexes collection
- CDaoIndexInfo structure [MFC]
ms.assetid: 251d8285-78ce-4716-a0b3-ccc3395fc437
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7d07193e43198797b31519b042b9f813676e08c2
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37121451"
---
# <a name="cdaoindexinfo-structure"></a>Estrutura CDaoIndexInfo

O `CDaoIndexInfo` estrutura contém informações sobre um objeto de índice definida para os objetos de acesso de dados (DAO).

## <a name="syntax"></a>Sintaxe

```cpp
struct CDaoIndexInfo {
    CDaoIndexInfo();                    // Constructor
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

### <a name="parameters"></a>Parâmetros

*m_strName*  
Exclusivamente nomeia o objeto de campo. Para obter detalhes, consulte o tópico "Propriedade de nome" na Ajuda do DAO.

*m_pFieldInfos*  
Um ponteiro para uma matriz de [CDaoIndexFieldInfo](../../mfc/reference/cdaoindexfieldinfo-structure.md) objetos indicando quais campos tabledef ou conjunto de registros são campos de chave em um índice. Cada objeto identifica um campo no índice. A ordem de índice padrão é crescente. Um objeto de índice pode ter um ou mais campos que representam as chaves de índice para cada registro. Eles podem ser crescente, decrescente, ou uma combinação.

*m_nFields*  
O número de campos armazenados em `m_pFieldInfos`.

*m_bPrimary*  
Se a propriedade primária é **TRUE**, o objeto de índice representa um índice primário. Um índice primário consiste em um ou mais campos que identificam exclusivamente a todos os registros em uma tabela em uma ordem predefinida. Como o campo de índice deve ser exclusivo, a propriedade exclusiva do objeto Index também é definida como **TRUE** em DAO. Se o índice primário consistir em mais de um campo, cada campo pode conter valores duplicados, mas cada combinação de valores de todos os campos indexados deve ser exclusiva. Um índice primário consiste em uma chave para a tabela e geralmente contém os mesmos campos de chave primária.

Quando você definir uma chave primária para uma tabela, a chave primária é automaticamente definida como o índice primário da tabela. Para obter mais informações, consulte os tópicos "Propriedade primária" e "Propriedade exclusiva" na Ajuda do DAO.

> [!NOTE]
> Pode haver, no máximo, um índice primário em uma tabela.

*m_bUnique*  
Indica se um objeto de índice representa um índice exclusivo para uma tabela. Se essa propriedade for **TRUE**, o objeto de índice representa um índice exclusivo. Um índice exclusivo consiste em um ou mais campos que organizam logicamente todos os registros em uma tabela em uma ordem exclusiva e predefinida. Se o índice consiste em um campo, os valores nesse campo devem ser exclusivos para a tabela inteira. Se o índice consiste em mais de um campo, cada campo pode conter valores duplicados, mas cada combinação de valores de todos os campos indexados deve ser exclusiva.

Se as propriedades de exclusiva e primária de um objeto de índice são definidas como **TRUE**, o índice é exclusiva e primária: identifica exclusivamente todos os registros na tabela em uma ordem lógica predefinida. Se a propriedade principal for definida como **FALSE**, o índice é um índice secundário. Índices secundários (chave e não chave) organizam logicamente os registros em uma ordem predefinida sem servir como um identificador para os registros na tabela.

Para obter mais informações, consulte os tópicos "Propriedade primária" e "Propriedade exclusiva" na Ajuda do DAO.

*m_bClustered*  
Indica se um objeto de índice representa um índice clusterizado para uma tabela. Se essa propriedade for **TRUE**, o objeto de índice representa um índice clusterizado; caso contrário, não. Um índice clusterizado consiste em uma ou mais não sejam chaves campos que, juntos, organizar todos os registros em uma tabela em uma ordem predefinida. Com um índice clusterizado, os dados na tabela literalmente são armazenados na ordem especificada pelo índice clusterizado. Um índice clusterizado fornece acesso eficiente aos registros em uma tabela. Para obter mais informações, consulte o tópico "Propriedade Clustered" na Ajuda do DAO.

> [!NOTE]
> A propriedade Clustered é ignorada para bancos de dados que usam o mecanismo de banco de dados do Microsoft Jet porque o mecanismo de banco de dados Jet não oferece suporte a índices clusterizados.

*m_bIgnoreNulls*  
Indica se há entradas de índice para registros com valores nulos em seus campos de índice. Se essa propriedade for **TRUE**, campos com valores nulos não têm uma entrada de índice. Para tornar procurando registros usando um campo mais rapidamente, você pode definir um índice para o campo. Se você permitir que as entradas Null em um campo indexado e espera que muitas das entradas de NULL, você pode definir a propriedade Ignorar para o objeto de índice para **TRUE** para reduzir a quantidade de espaço de armazenamento que usa o índice. A configuração da propriedade ignorar e a configuração de propriedade necessário juntas determinam se um registro com um valor de índice Null tem uma entrada de índice, como mostra a tabela a seguir.

|Ignorar|Necessária|Nulo no campo de índice|
|-----------------|--------------|-------------------------|
|verdadeiro|False|Valor nulo é permitido; Nenhuma entrada de índice foi adicionada.|
|False|False|Valor nulo é permitido; entrada de índice adicionada.|
|True ou False|verdadeiro|Valor nulo não permitido. Nenhuma entrada de índice foi adicionada.|

Para obter mais informações, consulte o tópico "Propriedade ignorar" na Ajuda do DAO.

*m_bRequired*  
Indica se um objeto de índice DAO requer um valor não nulo. Se essa propriedade for **TRUE**, o objeto de índice não permite que um valor Null. Para obter mais informações, consulte o tópico "Propriedade necessária" na Ajuda do DAO.

> [!TIP]
> Quando você pode definir essa propriedade para um objeto de índice DAO ou um objeto de campo (contido por um, conjunto de registros, objeto tabledef ou querydef), defina-a para o objeto de campo. A validade da configuração da propriedade para um objeto de campo é verificada antes que um objeto de índice.

*m_bForeign*  
Indica se um objeto de índice representa uma chave estrangeira em uma tabela. Se essa propriedade for **TRUE**, o índice representa uma chave estrangeira em uma tabela. Uma chave estrangeira consiste em um ou mais campos em uma tabela externa que identificam exclusivamente uma linha em uma tabela primária. O mecanismo de banco de dados Microsoft Jet cria um objeto de índice para a tabela externa e define a propriedade externa quando você cria um relacionamento que impõe a integridade referencial. Para obter mais informações, consulte o tópico "Propriedade externa" na Ajuda do DAO.

*m_lDistinctCount*  
Indica o número de valores exclusivos para o objeto de índice que estão incluídos na tabela associada. Verifique a propriedade DistinctCount para determinar o número de valores exclusivos, ou chaves, em um índice. Nenhuma chave é contado apenas uma vez, mesmo que haja várias ocorrências desse valor se o índice permite valores duplicados. Essa informação é útil em aplicativos que tentam otimizar o acesso a dados pela avaliação de informações de índice. O número de valores exclusivos é também conhecido como a cardinalidade de um objeto de índice. A propriedade DistinctCount será nem sempre reflete o número real de chaves em um momento específico. Por exemplo, uma alteração causada por uma reversão de transação não aparecerá imediatamente na propriedade DistinctCount. Para obter mais informações, consulte o tópico "Propriedade DistinctCount" na Ajuda do DAO.

## <a name="remarks"></a>Comentários

As referências para o primário, secundário e todos os acima indicam como as informações são retornadas pelo `GetIndexInfo` a função de membro em classes [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getindexinfo) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getindexinfo).

Objetos de índice não são representados por uma classe do MFC. Em vez disso, DAO objetos subjacentes objetos MFC classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) contém uma coleção de objetos de índice, chamado de coleção de índices. Essas classes fornecem funções de membro para acessar itens individuais de informações de índice, ou você pode acessá-los todos de uma vez com um `CDaoIndexInfo` objeto chamando o `GetIndexInfo` a função de membro do objeto contentor.

`CDaoIndexInfo` tem um construtor e um destruidor para corretamente aloque e desaloque as informações de campo de índice em `m_pFieldInfos`.

As informações recuperadas pelo `GetIndexInfo` a função de membro de um objeto tabledef é armazenada em um `CDaoIndexInfo` estrutura. Chamar o `GetIndexInfo` a função de membro do objeto contentor tabledef cuja coleção de índices, o objeto de índice é armazenado. `CDaoIndexInfo` também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoIndexInfo` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)  
[CDaoTableDef::GetIndexInfo](../../mfc/reference/cdaotabledef-class.md#getindexinfo)  
