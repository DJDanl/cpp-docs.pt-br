---
title: Estrutura CDaoFieldInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- CDaoFieldInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), Fields collection
- CDaoFieldInfo structure [MFC]
ms.assetid: 91b13e3f-bdb8-440c-86fc-ba4181ea0182
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 63fdab9bae7238f427ff2015beffd53570603af4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 `m_strName`  
 Exclusivamente nomeia o objeto de campo. Para obter detalhes, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
 `m_nType`  
 Um valor que indica o tipo de dados do campo. Para obter detalhes, consulte o tópico "Propriedade do tipo" na Ajuda do DAO. O valor dessa propriedade pode ser um dos seguintes:  
  
- **dbBoolean** Sim/Não, mesmo que **TRUE**/**FALSE**  
  
- **dbByte** bytes  
  
- **dbInteger** curto  
  
- **dbLong** longo  
  
- **dbCurrency** moeda; consulte MFC classe [COleCurrency](../../mfc/reference/colecurrency-class.md)  
  
- **dbSingle** único  
  
- **dbDouble** duplo  
  
- **dbDate** data/hora; consulte MFC classe [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)  
  
- **dbText** texto; consulte MFC classe [CString](../../atl-mfc-shared/reference/cstringt-class.md)  
  
- **dbLongBinary** binário longo (objeto OLE); talvez você queira usar a classe do MFC [CByteArray](../../mfc/reference/cbytearray-class.md) em vez da classe `CLongBinary` como `CByteArray` é mais avançada e fácil de usar.  
  
- **dbMemo** memorando; consulte classe do MFC`CString`  
  
- **dbGUID** um identificador global exclusivo/universalmente identificador exclusivo usado com chamadas de procedimento remoto. Para obter mais informações, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.  
  
> [!NOTE]
>  Não use os tipos de dados de cadeia de caracteres para dados binários. Isso faz com que seus dados passar a camada de conversão Unicode/ANSI, resultando em maior sobrecarga e possivelmente inesperada tradução.  
  
 *m_lSize*  
 Um valor que indica o tamanho máximo, em bytes, de um objeto de campo DAO que contém o texto ou o tamanho fixo de um objeto de campo que contém os valores de texto quanto numéricos. Para obter detalhes, consulte o tópico "Propriedade Size" na Ajuda do DAO. Tamanhos de podem ser um dos seguintes valores:  
  
|Tipo|Tamanho (Bytes)|Descrição|  
|----------|--------------------|-----------------|  
|**dbBoolean**|1 byte|Sim/não (igual a verdadeiro/falso)|  
|**dbByte**|1|Byte|  
|**dbInteger**|2|Inteiro|  
|**dbLong**|4|Long|  
|**dbCurrency**|8|Moeda ([COleCurrency](../../mfc/reference/colecurrency-class.md))|  
|**dbSingle**|4|Simples|  
|**dbDouble**|8|Duplo|  
|**dbDate**|8|Data/hora ([COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md))|  
|**dbText**|1 - 255|Texto ([CString](../../atl-mfc-shared/reference/cstringt-class.md))|  
|**dbLongBinary**|0|Binário longo (objeto OLE; [CByteArray](../../mfc/reference/cbytearray-class.md); usar em vez de `CLongBinary`)|  
|**dbMemo**|0|Memorando ([CString](../../atl-mfc-shared/reference/cstringt-class.md))|  
|**dbGUID**|16|Um identificador global exclusivo/universalmente identificador exclusivo usado com chamadas de procedimento remoto.|  
  
 `m_lAttributes`  
 Especifica as características de um objeto de campo contido por um tabledef, conjunto de registros, querydef ou objeto de índice. O valor retornado pode ser uma soma das constantes, criados com o C++ OR bit a bit (**&#124;**) operador:  
  
- **dbFixedField** o tamanho do campo é fixo (padrão para campos numéricos).  
  
- **dbVariableField** o tamanho do campo é variável (somente para campos de texto).  
  
- **dbAutoIncrField** o valor do campo para novos registros é incrementado automaticamente para um inteiro longo exclusivo que não pode ser alterado. Suporte apenas para tabelas de banco de dados Microsoft Jet.  
  
- **dbUpdatableField** o valor do campo pode ser alterado.  
  
- **dbDescending** o campo é classificado em decrescente (Z - A ou 0 a 100) ordem (aplica-se somente ao objeto campo em uma coleção de campos de um objeto de índice; em MFC, o índice se objetos estão contidos nos objetos tabledef). Se você omitir essa constante, o campo será classificado em crescente (A - Z ou 0 - 100) ordem (padrão).  
  
 Ao verificar a configuração dessa propriedade, você pode usar o C++ bit a bit- e operador (**&**) para testar um atributo específico. Ao definir vários atributos, você pode combiná-los, combinando as constantes apropriadas com OR bit a bit (**&#124;**) operador. Para obter detalhes, consulte o tópico "Propriedade atributos" na Ajuda do DAO.  
  
 *m_nOrdinalPosition*  
 Um valor que especifica a ordem numérica no qual você deseja que um campo representado por um objeto DAO do campo a ser exibido em relação a outros campos. Você pode definir essa propriedade com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield). Para obter detalhes, consulte o tópico "Propriedade OrdinalPosition" na Ajuda do DAO.  
  
 `m_bRequired`  
 Indica se um objeto de campo DAO requer um valor não nulo. Se essa propriedade for **TRUE**, o campo não permite que um valor Null. Se necessário for definido como **FALSE**, o campo pode conter valores nulos, bem como os valores que atendem às condições especificadas pelas configurações das propriedades Permitir comprimento zero e a regra de validação. Para obter detalhes, consulte o tópico "Propriedade necessária" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
 *m_bAllowZeroLength*  
 Indica se uma cadeia de caracteres vazia ("") é um valor válido de um objeto DAO de campo com um tipo de dados de texto ou Memorando. Se essa propriedade for **TRUE**, uma cadeia de caracteres vazia é um valor válido. Você pode definir essa propriedade **FALSE** para garantir que você não pode usar uma cadeia de caracteres vazia para definir o valor de um campo. Para obter detalhes, consulte o tópico "Propriedade Permitir comprimento zero" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
 `m_lCollatingOrder`  
 Especifica a sequência da ordem de classificação no texto de comparação de cadeia de caracteres ou classificação. Para obter detalhes, consulte o tópico "Personalizando Windows registro as configurações de acesso a dados" na Ajuda do DAO. Para obter uma lista dos possíveis valores retornados, consulte o **m_lCollatingOrder** membro o [CDaoDatabaseInfo](../../mfc/reference/cdaodatabaseinfo-structure.md) estrutura. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
 `m_strForeignName`  
 Um valor que, em uma relação, especifica o nome do objeto DAO campo em uma tabela externa que corresponde a um campo em uma tabela primária. Para obter detalhes, consulte o tópico "Propriedade ForeignName" na Ajuda do DAO.  
  
 *m_strSourceField*  
 Indica o nome do campo que é a fonte original dos dados de um objeto de campo DAO contido por um objeto de querydef, tabledef ou conjunto de registros. Essa propriedade indica o nome do campo original associado a um objeto de campo. Por exemplo, você pode usar essa propriedade para determinar a origem dos dados em um campo de consulta cujo nome não está relacionado ao nome do campo na tabela base. Para obter detalhes, consulte o tópico "Propriedades SourceField e SourceTable" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
 *m_strSourceTable*  
 Indica o nome da tabela que é a fonte original dos dados de um objeto de campo DAO contido por um objeto de querydef, tabledef ou conjunto de registros. Essa propriedade indica o nome da tabela original associado a um objeto de campo. Por exemplo, você pode usar essa propriedade para determinar a origem dos dados em um campo de consulta cujo nome não está relacionado ao nome do campo na tabela base. Para obter detalhes, consulte o tópico "Propriedades SourceField e SourceTable" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
 `m_strValidationRule`  
 Um valor que valida os dados em um campo, pois ele é alterado nem adicionado a uma tabela. Para obter detalhes, consulte o tópico "Propriedade ValidationRule" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
 Para obter informações relacionadas sobre tabledefs, consulte o **m_strValidationRule** membro o [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) estrutura.  
  
 `m_strValidationText`  
 Um valor que especifica o texto da mensagem que seu aplicativo exibe se o valor de um objeto de campo do DAO não atendem à regra de validação especificada pela configuração da propriedade de regra de validação. Para obter detalhes, consulte o tópico "Propriedade de texto de validação" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
 *m_strDefaultValue*  
 O valor padrão de um objeto de campo DAO. Quando um novo registro é criado, a configuração da propriedade DefaultValue é inserida automaticamente como o valor do campo. Para obter detalhes, consulte o tópico "Propriedade DefaultValue" na Ajuda do DAO. Você pode definir essa propriedade para um tabledef com [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield).  
  
## <a name="remarks"></a>Comentários  
 As referências para o primário, secundário e todos os acima indicam como as informações são retornadas pelo `GetFieldInfo` a função de membro em classes [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getfieldinfo), [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo), e [ CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getfieldinfo).  
  
 Objetos de campo não são representados por uma classe do MFC. Em vez disso, os objetos DAO MFC objetos das seguintes classes subjacentes contêm coleções de objetos de campo: [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md), [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md), e [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). Essas classes fornecem funções de membro para acessar alguns itens individuais de informações de campo, ou você pode acessá-los todos de uma vez com um `CDaoFieldInfo` objeto chamando o `GetFieldInfo` a função de membro do objeto contentor.  
  
 Além de seu uso para examinar as propriedades do objeto, você também pode usar `CDaoFieldInfo` para construir um parâmetro de entrada para a criação de novos campos em um tabledef. Opções mais simples estão disponíveis para essa tarefa, mas se você quiser um controle mais preciso, você pode usar a versão do [CDaoTableDef::CreateField](../../mfc/reference/cdaotabledef-class.md#createfield) que leva um `CDaoFieldInfo` parâmetro.  
  
 As informações recuperadas pelo `GetFieldInfo` função de membro (da classe que contém o campo) é armazenada em um `CDaoFieldInfo` estrutura. Chamar o `GetFieldInfo` a função de membro do objeto contentor cuja coleção de campos do objeto de campo é armazenado. `CDaoFieldInfo`também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoFieldInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDaoTableDef::GetFieldInfo](../../mfc/reference/cdaotabledef-class.md#getfieldinfo)   
 [CDaoRecordset::GetFieldInfo](../../mfc/reference/cdaorecordset-class.md#getfieldinfo)   
 [CDaoQueryDef::GetFieldInfo](../../mfc/reference/cdaoquerydef-class.md#getfieldinfo)

