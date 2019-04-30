---
title: Estrutura CDaoFieldInfo
ms.date: 11/04/2016
f1_keywords:
- CDaoFieldInfo
helpviewer_keywords:
- DAO (Data Access Objects), Fields collection
- CDaoFieldInfo structure [MFC]
ms.assetid: 91b13e3f-bdb8-440c-86fc-ba4181ea0182
ms.openlocfilehash: a5c4013a323c85ad19a3fade20f76852e053362a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399818"
---
# <a name="cdaofieldinfo-structure"></a>Estrutura CDaoFieldInfo

O `CDaoFieldInfo` estrutura contém informações sobre um objeto de campo definido para objetos de acesso de dados (DAO).

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
Exclusivamente nomeia o objeto de campo. Para obter detalhes, consulte o tópico "Propriedade de nome" na Ajuda do DAO.

*m_nType*<br/>
Um valor que indica o tipo de dados do campo. Para obter detalhes, consulte o tópico "Propriedade do tipo" na Ajuda do DAO. O valor dessa propriedade pode ser um dos seguintes:

- `dbBoolean` Sim/não igual a verdadeiro/falso

- `dbByte` Byte

- `dbInteger` curto

- `dbLong` Longas

- `dbCurrency` Moeda; classe do MFC consulte [COleCurrency](../../mfc/reference/colecurrency-class.md)

- `dbSingle` Único

- `dbDouble` Double

- `dbDate` Data/hora; classe do MFC consulte [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)

- `dbText` Texto; classe do MFC consulte [CString](../../atl-mfc-shared/reference/cstringt-class.md)

- `dbLongBinary` Binário longo (objeto OLE); Você talvez queira usar a classe do MFC [CByteArray](../../mfc/reference/cbytearray-class.md) em vez da classe `CLongBinary` como `CByteArray` é mais avançada e fácil de usar.

- `dbMemo` Memorando; Consulte classe do MFC `CString`

- `dbGUID` Um identificador global exclusivo/identificador universal exclusivo usado com chamadas de procedimento remoto. Para obter mais informações, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.

> [!NOTE]
>  Não use tipos de dados de cadeia de caracteres para dados binários. Isso faz com que seus dados de passagem, a camada de conversão Unicode/ANSI, resultando em maior sobrecarga e possivelmente inesperada de tradução.

*m_lSize*<br/>
Um valor que indica o tamanho máximo, em bytes, de um objeto de campo do DAO que contém o texto ou o tamanho fixo de um objeto de campo que contém os valores de texto ou numérica. Para obter detalhes, consulte o tópico "Propriedade de tamanho" na Ajuda do DAO. Tamanhos de podem ser um dos seguintes valores:

|Tipo|Tamanho (Bytes)|Descrição|
|----------|--------------------|-----------------|
|`dbBoolean`|1 byte|Sim/não (igual a verdadeiro/falso)|
|`dbByte`|1|Byte|
|`dbInteger`|2|Inteiro|
|`dbLong`|4|Long|
|`dbCurrency`|8|Moeda ([COleCurrency](../../mfc/reference/colecurrency-class.md))|
|`dbSingle`|4|Simples|
|`dbDouble`|8|Duplo|
|`dbDate`|8|Date/Time ([COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md))|
|`dbText`|1 - 255|Texto ([CString](../../atl-mfc-shared/reference/cstringt-class.md))|
|`dbLongBinary`|0|Binário longo (OLE Object; [CByteArray](../../mfc/reference/cbytearray-class.md); use em vez de `CLongBinary`)|
|`dbMemo`|0|Memo ([CString](../../atl-mfc-shared/reference/cstringt-class.md))|
|`dbGUID`|16|Um identificador global exclusivo/identificador universal exclusivo usado com chamadas de procedimento remoto.|

*m_lAttributes*<br/>
Especifica as características de um objeto de campo contido por um tabledef, conjunto de registros, querydef ou objeto de índice. O valor retornado pode ser uma soma das constantes, criados com o C++ OR bit a bit (**&#124;**) operador:

- `dbFixedField` O tamanho do campo é fixo (padrão para campos numéricos).

- `dbVariableField` O tamanho do campo é variável (somente para campos de texto).

- `dbAutoIncrField` O valor do campo para novos registros é incrementado automaticamente para um inteiro longo exclusivo que não pode ser alterado. Só tem suporte para tabelas de banco de dados Microsoft Jet.

- `dbUpdatableField` O valor do campo pode ser alterado.

- `dbDescending` O campo é classificado em decrescente (Z - A ou 0 a 100) ordem (aplica-se somente a um objeto de campo em uma coleção de campos de um objeto de índice; no MFC, o índice em si objetos estão contidos nos objetos tabledef). Se você omitir essa constante, o campo será classificado em crescente (A - Z ou 0 – 100) ordem (padrão).

Ao verificar a configuração dessa propriedade, você pode usar o C++ bit a bit- e operador (**&**) para testar se um atributo específico. Ao definir vários atributos, você pode combiná-los ao combinar as constantes apropriadas com OR bit a bit (**&#124;**) operador. Para obter detalhes, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.

*m_nOrdinalPosition*<br/>
Um valor que especifica a ordem numérica no qual você deseja que um campo representado por um objeto DAO do campo a ser exibido em relação a outros campos. Você pode definir essa propriedade com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield). Para obter detalhes, consulte o tópico "Propriedade OrdinalPosition" na Ajuda do DAO.

*m_bRequired*<br/>
Indica se um objeto de campo do DAO requer um valor não nulo. Se essa propriedade for TRUE, o campo não permite um valor Null. Se for necessário for definido como FALSE, o campo pode conter valores nulos, bem como valores que atendem às condições especificadas pelas configurações das propriedades Permitir comprimento zero e a regra de validação. Para obter detalhes, consulte o tópico "Propriedade necessária" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_bAllowZeroLength*<br/>
Indica se uma cadeia de caracteres vazia ("") é um valor válido de um objeto de campo do DAO com um tipo de dados de texto ou Memorando. Se essa propriedade for TRUE, uma cadeia de caracteres vazia é um valor válido. Você pode definir essa propriedade como FALSE para garantir que você não pode usar uma cadeia de caracteres vazia para definir o valor de um campo. Para obter detalhes, consulte o tópico "Propriedade Permitir comprimento zero", na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_lCollatingOrder*<br/>
Especifica a sequência da ordem de classificação em texto para comparação de cadeia de caracteres ou classificação. Para obter detalhes, consulte o tópico "Personalizando o Windows registro configurações para acesso a dados" na Ajuda do DAO. Para obter uma lista dos possíveis valores retornados, consulte o `m_lCollatingOrder` membro a [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) estrutura. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strForeignName*<br/>
Um valor que, em uma relação, e especifica o nome do objeto de campo DAO em uma tabela externa que corresponde a um campo em uma tabela primária. Para obter detalhes, consulte o tópico "Propriedade ForeignName" na Ajuda do DAO.

*m_strSourceField*<br/>
Indica o nome do campo que é a fonte original dos dados para um objeto de campo do DAO contido por um tabledef, conjunto de registros ou objeto querydef. Essa propriedade indica o nome do campo original associado a um objeto de campo. Por exemplo, você pode usar essa propriedade para determinar a origem dos dados em um campo de consulta cujo nome não está relacionado ao nome do campo na tabela subjacente. Para obter detalhes, consulte o tópico "SourceField e SourceTable propriedades" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strSourceTable*<br/>
Indica o nome da tabela que é a fonte original dos dados para um objeto de campo do DAO contido por um tabledef, conjunto de registros ou objeto querydef. Essa propriedade indica o nome da tabela original associado a um objeto de campo. Por exemplo, você pode usar essa propriedade para determinar a origem dos dados em um campo de consulta cujo nome não está relacionado ao nome do campo na tabela subjacente. Para obter detalhes, consulte o tópico "SourceField e SourceTable propriedades" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strValidationRule*<br/>
Um valor que valida os dados em um campo como ele é alterado ou adicionado a uma tabela. Para obter detalhes, consulte o tópico "Propriedade de regra de validação" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

Para obter informações relacionadas sobre tabledefs, consulte o `m_strValidationRule` membro a [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) estrutura.

*m_strValidationText*<br/>
Um valor que especifica o texto da mensagem que seu aplicativo exibe o valor de um objeto de campo do DAO satisfaça a regra de validação especificada pela configuração da propriedade de regra de validação. Para obter detalhes, consulte o tópico "Propriedade do texto de validação" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

*m_strDefaultValue*<br/>
O valor padrão de um objeto de campo do DAO. Quando um novo registro é criado, a configuração da propriedade DefaultValue é automaticamente inserida como o valor do campo. Para obter detalhes, consulte o tópico "Propriedade DefaultValue" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).

## <a name="remarks"></a>Comentários

As referências ao primário, secundário e todos acima indicam como as informações são retornadas pela `GetFieldInfo` função de membro em classes [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getfieldinfo), [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo), e [ CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getfieldinfo).

Objetos de campo não são representados por uma classe do MFC. Em vez disso, os objetos DAO MFC objetos das seguintes classes subjacentes contêm coleções de objetos de campo: [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md), [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md), e [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). Essas classes fornecem funções de membro para acessar alguns itens individuais de informações de campo, ou você pode acessá-los todos de uma vez com um `CDaoFieldInfo` objeto chamando o `GetFieldInfo` a função de membro do objeto contentor.

Além de seu uso para examinar as propriedades do objeto, você também pode usar `CDaoFieldInfo` para construir um parâmetro de entrada para a criação de novos campos em um tabledef. Opções mais simples estão disponíveis para essa tarefa, mas se você quiser um controle mais preciso, você pode usar a versão do [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield) que usa um `CDaoFieldInfo` parâmetro.

As informações recuperadas pelo `GetFieldInfo` função de membro (da classe que contém o campo) é armazenada em um `CDaoFieldInfo` estrutura. Chamar o `GetFieldInfo` a função de membro do objeto contentor cuja coleção de campos, o objeto de campo é armazenado. `CDaoFieldInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoFieldInfo` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDaoTableDef::GetFieldInfo](../../mfc/reference/cdaotabledef-class.md#getfieldinfo)<br/>
[CDaoRecordset::GetFieldInfo](../../mfc/reference/cdaorecordset-class.md#getfieldinfo)<br/>
[CDaoQueryDef::GetFieldInfo](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo)
