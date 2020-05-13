---
title: Estrutura CDaoFieldInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoFieldInfo
helpviewer_keywords:
- DAO (Data Access Objects), Fields collection
- CDaoFieldInfo structure [MFC]
ms.assetid: 91b13e3f-bdb8-440c-86fc-ba4181ea0182
ms.openlocfilehash: 9466386fefc6e5ab8fcf89bf497c1d5219e3e807
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368406"
---
# <a name="cdaofieldinfo-structure"></a>Estrutura CDaoFieldInfo

A `CDaoFieldInfo` estrutura contém informações sobre um objeto de campo definido para objetos de acesso a dados (DAO).

O DAO é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta.

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
Nomeie exclusivamente o objeto de campo. Para obter detalhes, consulte o tópico "Propriedade de nome" no DAO Help.

*m_nType*<br/>
Um valor que indica o tipo de dados do campo. Para obter detalhes, consulte o tópico "Tipo propriedade" no DAO Help. O valor desta propriedade pode ser um dos seguintes:

- `dbBoolean`Sim/Não, o mesmo que TRUE/FALSE

- `dbByte`Byte

- `dbInteger`Curto

- `dbLong`Longas

- `dbCurrency`Moeda; ver Classe MFC [COleCurrency](../../mfc/reference/colecurrency-class.md)

- `dbSingle`Único

- `dbDouble`Duplo

- `dbDate`Data/hora; ver Classe MFC [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)

- `dbText`Texto; ver Classe MFC [CString](../../atl-mfc-shared/reference/cstringt-class.md)

- `dbLongBinary`Binário Longo (Objeto OLE); você pode querer usar a classe [MFC CByteArray](../../mfc/reference/cbytearray-class.md) em vez de classe `CLongBinary` como `CByteArray` é mais rico e fácil de usar.

- `dbMemo`Memorando; ver classe MFC`CString`

- `dbGUID`Um identificador globalmente único/identificador universalmente único usado com chamadas de procedimento remoto. Para obter mais informações, consulte o tópico "Tipo propriedade" no DAO Help.

> [!NOTE]
> Não use tipos de dados de string para dados binários. Isso faz com que seus dados passem pela camada de tradução Unicode/ANSI, resultando em maior sobrecarga e possivelmente tradução inesperada.

*m_lSize*<br/>
Um valor que indica o tamanho máximo, em bytes, de um objeto de campo DAO que contém texto ou o tamanho fixo de um objeto de campo que contém valores de texto ou numéricos. Para obter detalhes, consulte o tópico "Size Property" no DAO Help. Tamanhos podem ser um dos seguintes valores:

|Type|Tamanho (Bytes)|Descrição|
|----------|--------------------|-----------------|
|`dbBoolean`|1 byte|Sim/Não (o mesmo que True/False)|
|`dbByte`|1|Byte|
|`dbInteger`|2|Integer|
|`dbLong`|4|long|
|`dbCurrency`|8|Moeda[(COleCurrency)](../../mfc/reference/colecurrency-class.md)|
|`dbSingle`|4|Single|
|`dbDouble`|8|Double|
|`dbDate`|8|Data/hora[(COleDateTime)](../../atl-mfc-shared/reference/coledatetime-class.md)|
|`dbText`|1 - 255|Texto[(CString)](../../atl-mfc-shared/reference/cstringt-class.md)|
|`dbLongBinary`|0|Binário longo (Objeto OLE; [CByteArray;](../../mfc/reference/cbytearray-class.md) usar em `CLongBinary`vez de )|
|`dbMemo`|0|Memorando[(CString)](../../atl-mfc-shared/reference/cstringt-class.md)|
|`dbGUID`|16|Um identificador globalmente único/identificador universalmente único usado com chamadas de procedimento remoto.|

*m_lAttributes*<br/>
Especifica características de um objeto de campo contido por um objeto tabledef, recordset, querydef ou index. O valor devolvido pode ser uma soma dessas constantes, criadas com o operador C++ bitwise-OR** (&#124;): **

- `dbFixedField`O tamanho do campo é fixo (padrão para campos numéricos).

- `dbVariableField`O tamanho do campo é variável (somente campos de texto).

- `dbAutoIncrField`O valor de campo para novos registros é automaticamente incrementado a um inteiro longo único que não pode ser alterado. Apenas suportado para tabelas de banco de dados do Microsoft Jet.

- `dbUpdatableField`O valor do campo pode ser alterado.

- `dbDescending`O campo é classificado em ordem descendente (Z - A ou 100 - 0) (aplica-se apenas a um objeto de campo em uma coleção fields de um objeto de índice; em MFC, objetos de índice são eles próprios contidos em objetos de tabledef). Se você omitir esta constante, o campo é classificado em ordem ascendente (A - Z ou 0 - 100) (padrão).

Ao verificar a configuração desta propriedade, você pode usar o**&** operador C++ bitwise-AND () para testar um atributo específico. Ao definir vários atributos, você pode combiná-los combinando as constantes apropriadas com o operador bitwise-OR** (&#124;). ** Para obter detalhes, consulte o tópico "Propriedades de atributos" no DAO Help.

*m_nOrdinalPosition*<br/>
Um valor que especifica a ordem numérica na qual você deseja que um campo representado por um objeto de campo DAO seja exibido em relação a outros campos. Você pode definir esta propriedade com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield). Para obter detalhes, consulte o tópico "OrdinalPosition Property" no DAO Help.

*m_bRequired*<br/>
Indica se um objeto de campo DAO requer um valor não nulo. Se esta propriedade for VERDADEIRA, o campo não permite um valor nulo. Se necessário estiver definido como FALSE, o campo pode conter valores nulos, bem como valores que atendam às condições especificadas pelas configurações de propriedade AllowZeroLength e ValidationRule. Para obter detalhes, consulte o tópico "Propriedade Necessária" na Ajuda da DAO. Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_bAllowZeroLength*<br/>
Indica se uma seqüência de string vazia ("") é um valor válido de um objeto de campo DAO com um tipo de dados De texto ou memorando. Se esta propriedade for TRUE, uma seqüência de string vazia é um valor válido. Você pode definir esta propriedade como FALSE para garantir que você não pode usar uma string vazia para definir o valor de um campo. Para obter detalhes, consulte o tópico "AllowZeroLength Property" na Ajuda da DAO. Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_lCollatingOrder*<br/>
Especifica a seqüência da ordem de classificação em texto para comparação ou classificação de seqüência. Para obter detalhes, consulte o tópico "Personalização das configurações de registro do Windows para acesso a dados" na Ajuda da DAO. Para obter uma lista dos possíveis `m_lCollatingOrder` valores retornados, consulte o membro da estrutura [CDaoDatabaseInfo.](../../mfc/reference/cdaodatabaseinfo-structure.md) Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strForeignName*<br/>
Um valor que, em uma relação, especifica o nome do objeto de campo DAO em uma tabela estrangeira que corresponde a um campo em uma tabela primária. Para obter detalhes, consulte o tópico "Propriedade ForeignName" no DAO Help.

*m_strSourceField*<br/>
Indica o nome do campo que é a fonte original dos dados para um objeto de campo DAO contido por um objeto tabledef, recordset ou querydef. Esta propriedade indica o nome de campo original associado a um objeto de campo. Por exemplo, você pode usar esta propriedade para determinar a fonte original dos dados em um campo de consulta cujo nome não está relacionado com o nome do campo na tabela subjacente. Para obter detalhes, consulte o tópico "SourceField, SourceTable Properties" no DAO Help. Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strSourceTable*<br/>
Indica o nome da tabela que é a fonte original dos dados para um objeto de campo DAO contido por um objeto tabledef, recordset ou querydef. Esta propriedade indica o nome da tabela original associado a um objeto de campo. Por exemplo, você pode usar esta propriedade para determinar a fonte original dos dados em um campo de consulta cujo nome não está relacionado com o nome do campo na tabela subjacente. Para obter detalhes, consulte o tópico "SourceField, SourceTable Properties" no DAO Help. Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strValidationRule*<br/>
Um valor que valida os dados em um campo à medida que são alterados ou adicionados a uma tabela. Para obter detalhes, consulte o tópico "ValidationRule Property" no DAO Help. Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

Para obter informações relacionadas sobre `m_strValidationRule` tabledefs, consulte o membro da estrutura [CDaoTableDefInfo.](../../mfc/reference/cdaotabledefinfo-structure.md)

*m_strValidationText*<br/>
Um valor que especifica o texto da mensagem que seu aplicativo exibe se o valor de um objeto de campo DAO não satisfazer a regra de validação especificada pela configuração de propriedade ValidationRule. Para obter detalhes, consulte o tópico "ValidationText Property" no DAO Help. Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strDefaultValue*<br/>
O valor padrão de um objeto de campo DAO. Quando um novo registro é criado, a configuração de propriedade DefaultValue é inserida automaticamente como o valor para o campo. Para obter detalhes, consulte o tópico "Propriedade padrãode valor" na ajuda da Dao. Você pode definir esta propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

## <a name="remarks"></a>Comentários

As referências a Principal, Secundário e Tudo acima indicam como `GetFieldInfo` as informações são retornadas pela função do membro nas classes [CDaoTableDef,](../../mfc/reference/cdaotabledef-class.md#getfieldinfo) [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo)e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getfieldinfo).

Os objetos de campo não são representados por uma classe MFC. Em vez disso, os objetos DAO subjacentes aos objetos MFC das seguintes classes contêm coleções de objetos de campo: [CDaoTableDef,](../../mfc/reference/cdaotabledef-class.md) [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)e [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). Essas classes fornecem funções de membros para acessar alguns itens individuais de informações `CDaoFieldInfo` de campo, ou você pode acessá-los todos de uma vez com um objeto, chamando a `GetFieldInfo` função membro do objeto que contém.

Além de seu uso para examinar propriedades `CDaoFieldInfo` de objetos, você também pode usar para construir um parâmetro de entrada para criar novos campos em uma tabledef. Opções mais simples estão disponíveis para esta tarefa, mas se você quiser um controle mais fino, `CDaoFieldInfo` você pode usar a versão de [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield) que leva um parâmetro.

As informações recuperadas pela função membro `GetFieldInfo` (da classe que `CDaoFieldInfo` contém o campo) são armazenadas em uma estrutura. Chame `GetFieldInfo` a função membro do objeto contendo em cuja coleção Campos o objeto de campo é armazenado. `CDaoFieldInfo`também define `Dump` uma função de membro em compilações de depuração. Você pode `Dump` usar para despejar `CDaoFieldInfo` o conteúdo de um objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Confira também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDaoTableDef::GetFieldInfo](../../mfc/reference/cdaotabledef-class.md#getfieldinfo)<br/>
[CDaoRecordset::GetFieldInfo](../../mfc/reference/cdaorecordset-class.md#getfieldinfo)<br/>
[CDaoQueryDef::GetFieldInfo](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo)
