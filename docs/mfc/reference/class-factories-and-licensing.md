---
title: Alocadores de classe e licenciamento
ms.date: 11/04/2016
helpviewer_keywords:
- class factories [MFC], and licensing
ms.assetid: 53c4856a-4062-46db-9f69-dd4339f746b3
ms.openlocfilehash: 18d86122e57af056a50a4d94bac89d65a7b71c7d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855703"
---
# <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento

Para criar uma instância do seu controle OLE, um aplicativo de contêiner chama uma função de membro da fábrica de classes do controle. Como seu controle é um objeto OLE real, a fábrica de classes é responsável pela criação de instâncias do seu controle. Cada classe de controle OLE deve ter uma fábrica de classes.

Outro recurso importante dos controles OLE é a sua capacidade de impor uma licença. O ControlWizard permite que você incorpore o licenciamento durante a criação do seu projeto de controle. Para obter mais informações sobre licenciamento de controle, consulte o artigo [controles ActiveX: licenciamento de um controle ActiveX](../../mfc/mfc-activex-controls-licensing-an-activex-control.md).

A tabela a seguir lista várias macros e funções usadas para declarar e implementar a fábrica de classes do controle e para licenciar seu controle.

### <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento

|||
|-|-|
|[DECLARE_OLECREATE_EX](#declare_olecreate_ex)|Declara a fábrica de classes para um controle OLE ou página de propriedades.|
|[IMPLEMENT_OLECREATE_EX](#implement_olecreate_ex)|Implementa a função de `GetClassID` do controle e declara uma instância da fábrica de classes.|
|[BEGIN_OLEFACTORY](#begin_olefactory)|Inicia a declaração de qualquer função de licenciamento.|
|[END_OLEFACTORY](#end_olefactory)|Encerra a declaração de qualquer função de licenciamento.|
|[AfxVerifyLicFile](#afxverifylicfile)|Verifica se um controle é licenciado para uso em um computador específico.|

##  <a name="declare_olecreate_ex"></a>DECLARE_OLECREATE_EX

Declara uma fábrica de classes e a função membro `GetClassID` de sua classe de controle.

```
DECLARE_OLECREATE_EX(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle.

### <a name="remarks"></a>Comentários

Use essa macro no arquivo de cabeçalho de classe de controle para um controle que não oferece suporte a licenciamento.

Observe que essa macro tem a mesma finalidade que o exemplo de código a seguir:

[!code-cpp[NVC_MFCAxCtl#14](../../mfc/reference/codesnippet/cpp/class-factories-and-licensing_1.h)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="implement_olecreate_ex"></a>IMPLEMENT_OLECREATE_EX

Implementa a fábrica de classes do controle e a função de membro [Getclassidid](../../mfc/reference/colecontrol-class.md#getclassid) de sua classe de controle.

```
IMPLEMENT_OLECREATE_EX(
   class_name,
    external_name,
    l,
    w1,
    w2,
    b1,
    b2,
    b3,
    b4,
    b5,
    b6,
    b7,
    b8)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de página de propriedades de controle.

*external_name*<br/>
O nome do objeto exposto aos aplicativos.

*l, W1, W2, B1, B2, B3, B4, B5, B6, B7, B8*<br/>
Componentes do CLSID da classe. Para obter mais informações sobre esses parâmetros, consulte os comentários para [IMPLEMENT_OLECREATE](run-time-object-model-services.md#implement_olecreate).

### <a name="remarks"></a>Comentários

Essa macro deve aparecer no arquivo de implementação para qualquer classe de controle que use a macro DECLARE_OLECREATE_EX ou a BEGIN_OLEFACTORY e END_OLEFACTORY macros. O nome externo é o identificador do controle OLE que é exposto a outros aplicativos. Os contêineres usam esse nome para solicitar um objeto dessa classe de controle.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="begin_olefactory"></a>BEGIN_OLEFACTORY

Inicia a declaração de sua fábrica de classes no arquivo de cabeçalho da classe de controle.

```
BEGIN_OLEFACTORY(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
Especifica o nome da classe de controle cuja fábrica de classes é.

### <a name="remarks"></a>Comentários

Declarações de funções de licenciamento de fábrica de classe devem começar imediatamente após BEGIN_OLEFACTORY.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="end_olefactory"></a>END_OLEFACTORY

Encerra a declaração da fábrica de classes do seu controle.

```
END_OLEFACTORY(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle cuja fábrica de classes é.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="afxverifylicfile"></a>AfxVerifyLicFile

Chame essa função para verificar se o arquivo de licença nomeado por `pszLicFileName` é válido para o controle OLE.

```
BOOL AFXAPI AfxVerifyLicFile(
    HINSTANCE  hInstance,
    LPCTSTR  pszLicFileName,
    LPOLESTR  pszLicFileContents,
    UINT cch = -1);
```

### <a name="parameters"></a>parâmetros

*hInstance*<br/>
O identificador de instância da DLL associada ao controle licenciado.

*pszLicFileName*<br/>
Aponta para uma cadeia de caracteres de caractere terminada em nulo que contém o nome de arquivo da licença.

*pszLicFileContents*<br/>
Aponta para uma sequência de bytes que deve corresponder à sequência encontrada no início do arquivo de licença.

*cch*<br/>
Número de caracteres em *pszLicFileContents*.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o arquivo de licença existir e começar com a sequência de caracteres em *pszLicFileContents*; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *cch* for-1, essa função usará:

[!code-cpp[NVC_MFC_Utilities#36](../../mfc/codesnippet/cpp/class-factories-and-licensing_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
