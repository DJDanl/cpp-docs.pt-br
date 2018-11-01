---
title: Alocadores de classe e licenciamento
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.macros.classes
helpviewer_keywords:
- class factories [MFC], and licensing
ms.assetid: 53c4856a-4062-46db-9f69-dd4339f746b3
ms.openlocfilehash: bfe4957312a3e1f5c08768af6fe96eb0c2e8b1f0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50514386"
---
# <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento

Para criar uma instância do seu controle OLE, um aplicativo de contêiner chama uma função de membro da fábrica de classe do controle. Como o controle é um objeto OLE real, a fábrica de classes é responsável pela criação de instâncias do seu controle. Cada classe de controle OLE deve ter uma fábrica de classes.

Outro recurso importante de controles OLE é sua capacidade de aplicar uma licença. ControlWizard permite incorporar o licenciamento durante a criação de seu projeto de controle. Para obter mais informações sobre o licenciamento de controle, consulte o artigo [controles ActiveX: licenciamento de um controle de ActiveX](../../mfc/mfc-activex-controls-licensing-an-activex-control.md).

A tabela a seguir lista várias macros e funções usadas para declarar e implementar a fábrica de classes do seu controle e a licença do seu controle.

### <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento

|||
|-|-|
|[DECLARE_OLECREATE_EX](#declare_olecreate_ex)|Declara a fábrica de classe para uma página de controle ou uma propriedade do OLE.|
|[IMPLEMENT_OLECREATE_EX](#implement_olecreate_ex)|Implementa o controle `GetClassID` de função e declara uma instância de fábrica de classes.|
|[BEGIN_OLEFACTORY](#begin_olefactory)|Começa a declaração de qualquer função de licenciamento.|
|[END_OLEFACTORY](#end_olefactory)|Termina a declaração de qualquer função de licenciamento.|
|[AfxVerifyLicFile](#afxverifylicfile)|Verifica se um controle está licenciado para uso em um computador específico.|

##  <a name="declare_olecreate_ex"></a>  DECLARE_OLECREATE_EX

Declara uma fábrica de classes e o `GetClassID` função de membro de sua classe de controle.

```
DECLARE_OLECREATE_EX(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe do controle.

### <a name="remarks"></a>Comentários

Use esta macro no arquivo de cabeçalho de classe de controle, para um controle que não oferece suporte para licenciamento.

Observe que essa macro tem a mesma finalidade como o exemplo de código a seguir:

[!code-cpp[NVC_MFCAxCtl#14](../../mfc/reference/codesnippet/cpp/class-factories-and-licensing_1.h)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="implement_olecreate_ex"></a>  IMPLEMENT_OLECREATE_EX

Implementa a fábrica de classes do seu controle e o [GetClassID](../../mfc/reference/colecontrol-class.md#getclassid) função de membro de sua classe de controle.

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

*class_name*<br/>
O nome da classe de página de propriedade do controle.

*external_name*<br/>
O nome do objeto exposto a aplicativos.

*l, w1, w2, b1, b2, b3, b4, b5, b6, b7, M8*<br/>
Componentes de CLSID da classe. Para obter mais informações sobre esses parâmetros, consulte os comentários para [IMPLEMENT_OLECREATE](run-time-object-model-services.md#implement_olecreate).

### <a name="remarks"></a>Comentários

Essa macro deve aparecer no arquivo de implementação para qualquer classe de controle que usa a macro DECLARE_OLECREATE_EX ou as macros BEGIN_OLEFACTORY e END_OLEFACTORY. O nome externo é o identificador do controle OLE que é exposta a outros aplicativos. Contêineres de usam esse nome para solicitar um objeto dessa classe de controle.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="begin_olefactory"></a>  BEGIN_OLEFACTORY

Começa a declaração de sua fábrica de classe no arquivo de cabeçalho de sua classe de controle.

```
BEGIN_OLEFACTORY(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
Especifica o nome da classe do controle cuja fábrica de classes que se trata.

### <a name="remarks"></a>Comentários

As declarações de fábrica de classes, funções de licenciamento devem começar imediatamente após BEGIN_OLEFACTORY.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="end_olefactory"></a>  END_OLEFACTORY

Termina a declaração de fábrica de classes do seu controle.

```
END_OLEFACTORY(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe do controle cuja fábrica de classes que se trata.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="afxverifylicfile"></a>  AfxVerifyLicFile

Chame essa função para verificar que o arquivo de licença nomeada pelo `pszLicFileName` é válido para o controle OLE.

```
BOOL AFXAPI AfxVerifyLicFile(
    HINSTANCE  hInstance,
    LPCTSTR  pszLicFileName,
    LPOLESTR  pszLicFileContents,
    UINT cch = -1);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
O identificador de instância da DLL associado ao controle licenciado.

*pszLicFileName*<br/>
Aponta para uma cadeia de caracteres com terminação nula que contém o nome do arquivo de licença.

*pszLicFileContents*<br/>
Aponta para uma sequência de bytes que deve corresponder à sequência encontrada no início do arquivo de licença.

*CCH*<br/>
Número de caracteres em *pszLicFileContents*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo de licença existe e começa com a sequência de caracteres em *pszLicFileContents*; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *cch* é -1, essa função usa:

[!code-cpp[NVC_MFC_Utilities#36](../../mfc/codesnippet/cpp/class-factories-and-licensing_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
