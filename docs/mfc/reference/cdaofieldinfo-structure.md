---
title: Estrutura CDaoFieldInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoFieldInfo
helpviewer_keywords:
- DAO (Data Access Objects), Fields collection
- CDaoFieldInfo structure [MFC]
ms.assetid: 91b13e3f-bdb8-440c-86fc-ba4181ea0182
ms.openlocfilehash: e98f5ba69f6702dd768cfe6605f993064e1b896c
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71096109"
---
# <a name="cdaofieldinfo-structure"></a>Estrutura CDaoFieldInfo

A `CDaoFieldInfo` estrutura contém informações sobre um objeto de campo definido para DAO (objetos de acesso a dados).

O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

## <a name="syntax"></a>Sintaxe

```
struct CDaoFieldInfo
{
    CString m_strName;           // Primary
    short m_nType;               // Primary
    long m_lSize;                // Primary
    long m_lAttributes;          // Primary
    short m_nOrdinalPosition;    // Secondary
    BOOL m_bRequired;            // Secondary
    BOOL m_bAllowZeroLength;     // Secondary
    long m_lCollatingOrder;      // Secondary
    CString m_strForeignName;    // Secondary
    CString m_strSourceField;    // Secondary
    CString m_strSourceTable;    // Secondary
    CString m_strValidationRule; // All
    CString m_strValidationText; // All
    CString m_strDefaultValue;   // All
};
```

#### <a name="parameters"></a>Parâmetros

*m_strName*<br/>
Nomeia exclusivamente o objeto Field. Para obter detalhes, consulte o tópico "propriedade de nome" na ajuda do DAO.

*m_nType*<br/>
Um valor que indica o tipo de dados do campo. Para obter detalhes, consulte o tópico "Type Property" na ajuda do DAO. O valor dessa propriedade pode ser um dos seguintes:

- `dbBoolean`Sim/Não, o mesmo que verdadeiro/falso

- `dbByte`Minuciosa

- `dbInteger`Baixo

- `dbLong`Longas

- `dbCurrency`Moeda consulte MFC Class [COleCurrency](../../mfc/reference/colecurrency-class.md)

- `dbSingle`Exclusivo

- `dbDouble`Clique

- `dbDate`Data/hora; consulte MFC Class [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)

- `dbText`Texto Confira classe do MFC [CString](../../atl-mfc-shared/reference/cstringt-class.md)

- `dbLongBinary`Binário longo (objeto OLE); Talvez você queira usar a classe MFC [CByteArray](../../mfc/reference/cbytearray-class.md) em vez da `CLongBinary` classe `CByteArray` , pois é mais rica e fácil de usar.

- `dbMemo`Campos consulte classe do MFC`CString`

- `dbGUID`Identificador global exclusivo/identificador universal exclusivo usado com chamadas de procedimento remoto. Para obter mais informações, consulte o tópico "Type Property" na ajuda do DAO.

> [!NOTE]
>  Não use tipos de dados de cadeia de caracteres para dados binários. Isso faz com que os dados passem pela camada de conversão Unicode/ANSI, resultando em maior sobrecarga e conversão possivelmente inesperada.

*m_lSize*<br/>
Um valor que indica o tamanho máximo, em bytes, de um objeto de campo DAO que contém texto ou o tamanho fixo de um objeto de campo que contém valores de texto ou numéricos. Para obter detalhes, consulte o tópico "propriedade de tamanho" na ajuda do DAO. Os tamanhos podem ser um dos seguintes valores:

|Tipo|Tamanho (Bytes)|Descrição|
|----------|--------------------|-----------------|
|`dbBoolean`|1 byte|Sim/não (o mesmo que verdadeiro/falso)|
|`dbByte`|1|Byte|
|`dbInteger`|2|Inteiro|
|`dbLong`|4|Long|
|`dbCurrency`|8|Moeda ([COleCurrency](../../mfc/reference/colecurrency-class.md))|
|`dbSingle`|4|Simples|
|`dbDouble`|8|Duplo|
|`dbDate`|8|Data/hora ([COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md))|
|`dbText`|1 - 255|Texto ([CString](../../atl-mfc-shared/reference/cstringt-class.md))|
|`dbLongBinary`|0|Binário longo (objeto OLE; [CByteArray](../../mfc/reference/cbytearray-class.md); usar em vez `CLongBinary`de)|
|`dbMemo`|0|Memorando ([CString](../../atl-mfc-shared/reference/cstringt-class.md))|
|`dbGUID`|16|Identificador global exclusivo/identificador universal exclusivo usado com chamadas de procedimento remoto.|

*m_lAttributes*<br/>
Especifica as características de um objeto Field contido por um objeto tabledef, recordset, QueryDef ou index. O valor retornado pode ser uma soma dessas constantes, criadas com o operador C++ bit-a- **&#124;** a-or ():

- `dbFixedField`O tamanho do campo é fixo (padrão para campos numéricos).

- `dbVariableField`O tamanho do campo é variável (somente campos de texto).

- `dbAutoIncrField`O valor do campo para novos registros é incrementado automaticamente para um inteiro longo e exclusivo que não pode ser alterado. Com suporte apenas para tabelas de banco de dados Microsoft Jet.

- `dbUpdatableField`O valor do campo pode ser alterado.

- `dbDescending`O campo é classificado em ordem decrescente (Z-A ou 100-0) (aplica-se somente a um objeto Field em uma coleção Fields de um objeto index; no MFC, os objetos de índice estão contidos em objetos TableDef). Se você omitir essa constante, o campo será classificado em ordem crescente (A-Z ou 0-100) (padrão).

Ao verificar a configuração dessa propriedade, você pode usar o operador C++ and bit a bit ( **&** ) para testar um atributo específico. Ao definir vários atributos, você pode combiná-los combinando as constantes apropriadas com o operador bit- **&#124;** a-or (). Para obter detalhes, consulte o tópico "propriedade Attributes" na ajuda do DAO.

*m_nOrdinalPosition*<br/>
Um valor que especifica a ordem numérica na qual você deseja que um campo representado por um objeto de campo do DAO seja exibido em relação a outros campos. Você pode definir essa propriedade com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield). Para obter detalhes, consulte o tópico "Propriedade OrdinalPosition" na ajuda do DAO.

*m_bRequired*<br/>
Indica se um objeto de campo DAO requer um valor não nulo. Se essa propriedade for TRUE, o campo não permitirá um valor nulo. Se Required for definido como FALSE, o campo poderá conter valores nulos, bem como os valores que atendem às condições especificadas pelas configurações de propriedade AllowZeroLength e RegraDeValidação. Para obter detalhes, consulte o tópico "Propriedade necessária" na ajuda do DAO. Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_bAllowZeroLength*<br/>
Indica se uma cadeia de caracteres vazia ("") é um valor válido de um objeto de campo do DAO com um tipo de dados de texto ou memorando. Se essa propriedade for TRUE, uma cadeia de caracteres vazia será um valor válido. Você pode definir essa propriedade como FALSE para garantir que não seja possível usar uma cadeia de caracteres vazia para definir o valor de um campo. Para obter detalhes, consulte o tópico "Propriedade AllowZeroLength" na ajuda do DAO. Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_lCollatingOrder*<br/>
Especifica a sequência da ordem de classificação no texto para comparação ou classificação de cadeia de caracteres. Para obter detalhes, consulte o tópico "Personalizando configurações do registro do Windows para acesso a dados" na ajuda do DAO. Para obter uma lista dos possíveis valores retornados, consulte o `m_lCollatingOrder` membro da estrutura [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) . Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strForeignName*<br/>
Um valor que, em uma relação, especifica o nome do objeto de campo DAO em uma tabela estrangeira que corresponde a um campo em uma tabela primária. Para obter detalhes, consulte o tópico "Propriedade ForeignName" na ajuda do DAO.

*m_strSourceField*<br/>
Indica o nome do campo que é a fonte original dos dados para um objeto de campo DAO contido por um objeto tabledef, Recordset ou querydef. Essa propriedade indica o nome do campo original associado a um objeto Field. Por exemplo, você pode usar essa propriedade para determinar a fonte original dos dados em um campo de consulta cujo nome não está relacionado ao nome do campo na tabela subjacente. Para obter detalhes, consulte o tópico "Origemfield, propriedades de SourceTable" na ajuda do DAO. Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strSourceTable*<br/>
Indica o nome da tabela que é a fonte original dos dados para um objeto de campo DAO contido por um objeto tabledef, Recordset ou querydef. Esta propriedade indica o nome da tabela original associado a um objeto Field. Por exemplo, você pode usar essa propriedade para determinar a fonte original dos dados em um campo de consulta cujo nome não está relacionado ao nome do campo na tabela subjacente. Para obter detalhes, consulte o tópico "Origemfield, propriedades de SourceTable" na ajuda do DAO. Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strValidationRule*<br/>
Um valor que valida os dados em um campo à medida que eles são alterados ou adicionados a uma tabela. Para obter detalhes, consulte o tópico "Propriedade RegraDeValidação" na ajuda do DAO. Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

Para obter informações relacionadas sobre os TableDefs, `m_strValidationRule` consulte o membro da estrutura [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) .

*m_strValidationText*<br/>
Um valor que especifica o texto da mensagem que seu aplicativo exibe se o valor de um objeto de campo do DAO não atender à regra de validação especificada pela configuração da Propriedade RegraDeValidação. Para obter detalhes, consulte o tópico "Propriedade do TextoDeValidação" na ajuda do DAO. Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strDefaultValue*<br/>
O valor padrão de um objeto de campo do DAO. Quando um novo registro é criado, a configuração da Propriedade DefaultValue é inserida automaticamente como o valor do campo. Para obter detalhes, consulte o tópico "Propriedade DefaultValue" na ajuda do DAO. Você pode definir essa propriedade para um TableDef com [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield).

## <a name="remarks"></a>Comentários

As referências a primário, secundário e todos acima indicam como as informações são `GetFieldInfo` retornadas pela função de membro nas classes [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getfieldinfo), [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo)e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getfieldinfo).

Os objetos de campo não são representados por uma classe MFC. Em vez disso, os objetos DAO subjacentes aos objetos do MFC das seguintes classes contêm coleções de objetos de campo: [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md), [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)e [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). Essas classes fornecem funções de membro para acessar alguns itens individuais de informações de campo, ou você pode acessá-los de `CDaoFieldInfo` uma só vez com `GetFieldInfo` um objeto chamando a função de membro do objeto recipiente.

Além de seu uso para examinar as propriedades do objeto, você `CDaoFieldInfo` também pode usar para construir um parâmetro de entrada para criar novos campos em um TableDef. As opções mais simples estão disponíveis para essa tarefa, mas se você quiser um controle mais preciso, poderá usar a versão de [CDaoTableDef::](../../mfc/reference/cdaotabledef-class.md#createfield) que `CDaoFieldInfo` usa um parâmetro.

As informações recuperadas `GetFieldInfo` pela função de membro (da classe que contém o campo) são armazenadas em `CDaoFieldInfo` uma estrutura. Chame a `GetFieldInfo` função de membro do objeto recipiente em cuja coleção de campos o objeto de campo está armazenado. `CDaoFieldInfo`também define uma `Dump` função de membro em compilações de depuração. Você pode usar `Dump` para despejar o conteúdo de `CDaoFieldInfo` um objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDaoTableDef::GetFieldInfo](../../mfc/reference/cdaotabledef-class.md#getfieldinfo)<br/>
[CDaoRecordset::GetFieldInfo](../../mfc/reference/cdaorecordset-class.md#getfieldinfo)<br/>
[CDaoQueryDef::GetFieldInfo](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo)
