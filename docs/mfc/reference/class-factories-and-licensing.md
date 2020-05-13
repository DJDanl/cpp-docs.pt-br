---
title: Alocadores de classe e licenciamento
ms.date: 11/04/2016
helpviewer_keywords:
- class factories [MFC], and licensing
ms.assetid: 53c4856a-4062-46db-9f69-dd4339f746b3
ms.openlocfilehash: e3fed6520cdbe0fd964e4e80e7c9ed9b78296d16
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372303"
---
# <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento

Para criar uma instância do controle OLE, um aplicativo de contêiner chama uma função membro da fábrica de classes do controle. Como seu controle é um objeto OLE real, a fábrica de classes é responsável por criar instâncias do seu controle. Toda classe de controle OLE deve ter uma fábrica de classe.

Outra característica importante dos controles OLE é sua capacidade de aplicar uma licença. ControlWizard permite que você incorpore o licenciamento durante a criação do seu projeto de controle. Para obter mais informações sobre licenciamento de controle, consulte o artigo [ActiveX Controls: Licensing An ActiveX Control](../../mfc/mfc-activex-controls-licensing-an-activex-control.md).

A tabela a seguir lista várias macros e funções usadas para declarar e implementar a fábrica de classes do seu controle e licenciar o seu controle.

### <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento

|||
|-|-|
|[DECLARE_OLECREATE_EX](#declare_olecreate_ex)|Declara a fábrica de classe para uma página de controle ou propriedade OLE.|
|[IMPLEMENT_OLECREATE_EX](#implement_olecreate_ex)|Implementa a função `GetClassID` do controle e declara uma instância da fábrica de classe.|
|[BEGIN_OLEFACTORY](#begin_olefactory)|Começa a declaração de quaisquer funções de licenciamento.|
|[END_OLEFACTORY](#end_olefactory)|Termina a declaração de quaisquer funções de licenciamento.|
|[AfxVerifyLicFile](#afxverifylicfile)|Verifica se um controle é licenciado para uso em um computador específico.|

## <a name="declare_olecreate_ex"></a><a name="declare_olecreate_ex"></a>DECLARE_OLECREATE_EX

Declara uma fábrica de `GetClassID` classe e a função membro de sua classe de controle.

```
DECLARE_OLECREATE_EX(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle.

### <a name="remarks"></a>Comentários

Use esta macro no arquivo de cabeçalho da classe de controle para um controle que não suporta licenciamento.

Observe que esta macro serve ao mesmo propósito da seguinte amostra de código:

[!code-cpp[NVC_MFCAxCtl#14](../../mfc/reference/codesnippet/cpp/class-factories-and-licensing_1.h)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="implement_olecreate_ex"></a><a name="implement_olecreate_ex"></a>IMPLEMENT_OLECREATE_EX

Implementa a fábrica de classe do seu controle e a função de membro [GetClassID](../../mfc/reference/colecontrol-class.md#getclassid) da sua classe de controle.

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

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de página de propriedade de controle.

*external_name*<br/>
O nome do objeto exposto a aplicativos.

*l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8*<br/>
Componentes do CLSID da classe. Para obter mais informações sobre esses parâmetros, consulte as Observações para [IMPLEMENT_OLECREATE](run-time-object-model-services.md#implement_olecreate).

### <a name="remarks"></a>Comentários

Essa macro deve aparecer no arquivo de implementação para qualquer classe de controle que use a macro DECLARE_OLECREATE_EX ou as macros BEGIN_OLEFACTORY e END_OLEFACTORY. O nome externo é o identificador do controle OLE que é exposto a outras aplicações. Os contêineres usam este nome para solicitar um objeto desta classe de controle.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="begin_olefactory"></a><a name="begin_olefactory"></a>Begin_olefactory

Começa a declaração de sua fábrica de classe no arquivo de cabeçalho da sua classe de controle.

```
BEGIN_OLEFACTORY(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
Especifica o nome da classe de controle cuja classe é esta.

### <a name="remarks"></a>Comentários

As declarações das funções de licenciamento de fábrica de classe devem começar imediatamente após BEGIN_OLEFACTORY.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="end_olefactory"></a><a name="end_olefactory"></a>END_OLEFACTORY

Termina a declaração da fábrica de classe do seu controle.

```
END_OLEFACTORY(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle cuja classe é esta.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="afxverifylicfile"></a><a name="afxverifylicfile"></a>AfxVerifyLicFile

Ligue para esta função para verificar `pszLicFileName` se o arquivo de licença nomeado por é válido para o controle OLE.

```
BOOL AFXAPI AfxVerifyLicFile(
    HINSTANCE  hInstance,
    LPCTSTR  pszLicFileName,
    LPOLESTR  pszLicFileContents,
    UINT cch = -1);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
A alça de instância da DLL associada ao controle licenciado.

*pszLicFileName*<br/>
Aponta para uma seqüência de caracteres com término nulo contendo o nome do arquivo da licença.

*pszLicFileContents*<br/>
Aponta para uma seqüência de bytes que deve corresponder à seqüência encontrada no início do arquivo de licença.

*Cch*<br/>
Número de caracteres em *pszLicFileContents*.

### <a name="return-value"></a>Valor retornado

Não zero se o arquivo de licença existir e começar com a seqüência de *caracteres em pszLicFileContents*; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *cch* for -1, esta função usa:

[!code-cpp[NVC_MFC_Utilities#36](../../mfc/codesnippet/cpp/class-factories-and-licensing_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
