---
title: Classe CMetaFileDC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMetaFileDC
- AFXEXT/CMetaFileDC
- AFXEXT/CMetaFileDC::CMetaFileDC
- AFXEXT/CMetaFileDC::Close
- AFXEXT/CMetaFileDC::CloseEnhanced
- AFXEXT/CMetaFileDC::Create
- AFXEXT/CMetaFileDC::CreateEnhanced
dev_langs:
- C++
helpviewer_keywords:
- CMetaFileDC class
- Windows metafiles [C++]
- metafiles, implementing
ms.assetid: ffce60fa-4181-4d46-9832-25e46fad4db4
caps.latest.revision: 23
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 4bff4d7601c4ffbc6fe5cbe73f5e057b79abf1e5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmetafiledc-class"></a>Classe CMetaFileDC
Implementa um metarquivo do Windows, que contém uma sequência de comandos GDI (interface) do dispositivo de gráficos que você pode reproduzir para criar uma imagem desejada ou texto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMetaFileDC : public CDC  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMetaFileDC::CMetaFileDC](#cmetafiledc)|Constrói um objeto `CMetaFileDC`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMetaFileDC::Close](#close)|Fecha o contexto de dispositivo e cria um identificador de metarquivo.|  
|[CMetaFileDC::CloseEnhanced](#closeenhanced)|Fecha um contexto de dispositivo de metarquivo avançado e cria um identificador de metarquivo avançado.|  
|[CMetaFileDC::Create](#create)|Cria o contexto de dispositivo do Windows metafile e anexa-o para o `CMetaFileDC` objeto.|  
|[CMetaFileDC::CreateEnhanced](#createenhanced)|Cria um contexto de dispositivo para um metarquivo aprimorado formato metarquivo.|  
  
## <a name="remarks"></a>Comentários  
 Para implementar um metarquivo do Windows, primeiro crie uma `CMetaFileDC` objeto. Invocar o `CMetaFileDC` construtor, em seguida, chame o [criar](#create) a função de membro, que cria um contexto de dispositivo do Windows metafile e anexa-o para o `CMetaFileDC` objeto.  
  
 Em seguida enviar o `CMetaFileDC` objeto a sequência de `CDC` comandos GDI que você pretende para a reprodução. Somente os comandos GDI que criem saída, como `MoveTo` e `LineTo`, pode ser usado.  
  
 Depois que você enviou os comandos desejados para o metarquivo, chame o **fechar** função de membro, que fecha os contextos de dispositivo de metarquivo e retorna um identificador de metarquivo. Descarte o `CMetaFileDC` objeto.  
  
 [CDC::PlayMetaFile](../../mfc/reference/cdc-class.md#playmetafile) pode usar o identificador de metarquivo para executar o metarquivo repetidamente. O metarquivo também pode ser manipulado pelas funções do Windows como [CopyMetaFile](http://msdn.microsoft.com/library/windows/desktop/dd183480), que copia um metarquivo em disco.  
  
 Quando o metarquivo não for mais necessário, exclua-o da memória com o [DeleteMetaFile](http://msdn.microsoft.com/library/windows/desktop/dd183537) função do Windows.  
  
 Você também pode implementar o `CMetaFileDC` do objeto para que ele pode lidar com as duas chamadas de saída e atributo GDI chama como `GetTextExtent`. Tal um metarquivo é mais flexível e podem mais facilmente reutilizar código GDI geral, que geralmente consiste em uma mistura de chamadas de saída e de atributo. O `CMetaFileDC` classe herda dois contextos de dispositivo, `m_hDC` e `m_hAttribDC`, de `CDC`. O `m_hDC` contexto de dispositivo cuida de tudo [CDC](../../mfc/reference/cdc-class.md) GDI chamadas de saída e o `m_hAttribDC` contexto de dispositivo cuida de tudo `CDC` GDI chama de atributo. Normalmente, esses contextos de dois dispositivo consultem no mesmo dispositivo. No caso de `CMetaFileDC`, o controlador de domínio do atributo é definido como **nulo** por padrão.  
  
 Criar um segundo contexto de dispositivo que aponta para a tela, impressora ou dispositivo que não seja um metarquivo, em seguida, chame o `SetAttribDC` a função de membro para associar o novo contexto de dispositivo com `m_hAttribDC`. Chamadas GDI para obter informações agora serão direcionadas para o novo `m_hAttribDC`. Saída GDI chama para ir para `m_hDC`, que representa o metarquivo.  
  
 Para obter mais informações sobre `CMetaFileDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CDC](../../mfc/reference/cdc-class.md)  
  
 `CMetaFileDC`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="close"></a>CMetaFileDC::Close  
 Fecha o contexto de dispositivo de metarquivo e cria um identificador de metarquivo do Windows que pode ser usado para reproduzir o metarquivo usando o [CDC::PlayMetaFile](../../mfc/reference/cdc-class.md#playmetafile) função de membro.  
  
```  
HMETAFILE Close();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Válido **HMETAFILE** se a função for bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 O identificador de metarquivo do Windows também pode ser usado para manipular o metarquivo com funções do Windows como [CopyMetaFile](http://msdn.microsoft.com/library/windows/desktop/dd183480).  
  
 Excluir o metarquivo após o uso, chamando o Windows [DeleteMetaFile](http://msdn.microsoft.com/library/windows/desktop/dd183537) função.  
  
##  <a name="closeenhanced"></a>CMetaFileDC::CloseEnhanced  
 Fecha um contexto de dispositivo de metarquivo avançado e retorna um identificador que identifica um metarquivo aprimorado de formato.  
  
```  
HENHMETAFILE CloseEnhanced();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de um metarquivo avançado, se for bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo pode usar o identificador de metarquivo avançado retornado por essa função para executar as seguintes tarefas:  
  
-   Exibir uma imagem armazenada em um metarquivo avançado  
  
-   Crie cópias do metarquivo avançado  
  
-   Enumerar, editar ou copiar registros individuais de metarquivo avançado  
  
-   Recuperar uma descrição opcional do conteúdo metarquivo do cabeçalho de metarquivo avançado  
  
-   Recuperar uma cópia do cabeçalho de metarquivo avançado  
  
-   Recuperar uma cópia binária do metarquivo avançado  
  
-   Enumerar as cores na paleta opcional  
  
-   Converter um metarquivo aprimorado de formato em um formato Windows metafile  
  
 Quando o aplicativo não precisa mais o identificador de metarquivo avançado, ele deve liberar o identificador chamando Win32 **DeleteEnhMetaFile** função.  
  
##  <a name="cmetafiledc"></a>CMetaFileDC::CMetaFileDC  
 Construir uma `CMetaFileDC` objeto em duas etapas.  
  
```  
CMetaFileDC();
```  
  
### <a name="remarks"></a>Comentários  
 Primeiro, chame `CMetaFileDC`, em seguida, chame **criar**, que cria o contexto de dispositivo do Windows metafile e anexa-o para o `CMetaFileDC` objeto.  
  
##  <a name="create"></a>CMetaFileDC::Create  
 Construir uma `CMetaFileDC` objeto em duas etapas.  
  
```  
BOOL Create(LPCTSTR lpszFilename = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszFilename*  
 Aponta para uma cadeia de caracteres terminada em nulo. Especifica o nome do arquivo do metarquivo para criar. Se *lpszFilename* é **nulo**, é criado um novo metarquivo na memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Primeiro, chame o construtor `CMetaFileDC`, em seguida, chame **criar**, que cria o contexto de dispositivo do Windows metafile e anexa-o para o `CMetaFileDC` objeto.  
  
##  <a name="createenhanced"></a>CMetaFileDC::CreateEnhanced  
 Cria um contexto de dispositivo para um metarquivo aprimorado de formato.  
  
```  
BOOL CreateEnhanced(
    CDC* pDCRef,  
    LPCTSTR lpszFileName,  
    LPCRECT lpBounds,  
    LPCTSTR lpszDescription);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDCRef`  
 Identifica um dispositivo de referência para o metarquivo avançado.  
  
 `lpszFileName`  
 Aponta para uma cadeia de caracteres terminada em nulo. Especifica o nome do arquivo para o metarquivo a ser criado. Se esse parâmetro for **nulo**, o metarquivo avançado é memória com base e seu conteúdo perdido quando o objeto é destruído ou Win32 **DeleteEnhMetaFile** função é chamada.  
  
 `lpBounds`  
 Aponta para um [RECT](../../mfc/reference/rect-structure1.md) estrutura de dados ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as dimensões em **HIMETRIC** unidades (em incrementos de.01 milímetro) da imagem a ser armazenado no metarquivo avançado.  
  
 `lpszDescription`  
 Aponta para uma cadeia de caracteres terminada em zero que especifica o nome do aplicativo que criou a imagem, bem como o título da imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de contexto do dispositivo para o metarquivo avançado, se for bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esse controlador de domínio pode ser usado para armazenar uma imagem independente de dispositivo.  
  
 O Windows usa o dispositivo de referência identificado pelo `pDCRef` parâmetro para registrar a resolução e unidades do dispositivo no qual uma imagem apareceu originalmente. Se o `pDCRef` parâmetro é **nulo**, ele usa o dispositivo de vídeo atual para referência.  
  
 Os membros da esquerda e superior do `RECT` dados estrutura apontada pelo `lpBounds` parâmetro deve ser menor do que os membros direita e inferior, respectivamente. Pontos ao longo das bordas do retângulo estão incluídos na imagem. Se `lpBounds` é **nulo**, a interface gráfica de dispositivo (GDI) computa as dimensões do retângulo menor que pode colocar a imagem desenhada pelo aplicativo. O `lpBounds` parâmetro deve ser fornecido quando possível.  
  
 A cadeia de caracteres apontada pelo `lpszDescription` parâmetro deve conter um caractere nulo entre o nome do aplicativo e o nome da imagem e deve terminar com dois caracteres nulos — por exemplo, "XYZ gráficos Editor\0Bald Eagle\0\0," onde \0 representa o caractere nulo. Se `lpszDescription` é **nulo**, não há nenhuma entrada correspondente no cabeçalho de metarquivo avançado.  
  
 Aplicativos usam o controlador de domínio criado por essa função para armazenar uma imagem de elementos gráficos em um metarquivo avançado. O identificador identifica esse controlador de domínio pode ser passado a qualquer função GDI.  
  
 Depois que um aplicativo armazena uma imagem em um metarquivo avançado, ele pode exibir a imagem em qualquer dispositivo de saída chamando o `CDC::PlayMetaFile` função. Ao exibir a imagem, o Windows usa o retângulo apontado pelo `lpBounds` parâmetro e os dados de resolução do dispositivo de referência para posicionar e dimensionar a imagem. O contexto de dispositivo retornado por essa função contém os mesmos atributos padrão associados a qualquer novo controlador de domínio.  
  
 Os aplicativos devem usar o Win32 **GetWinMetaFileBits** function para converter um metarquivo avançado para o antigo formato de metarquivo do Windows.  
  
 O nome do arquivo para o metarquivo avançado deve usar o. Extensão EMF.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDC](../../mfc/reference/cdc-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




