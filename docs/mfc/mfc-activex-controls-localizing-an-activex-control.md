---
title: 'Controles MFC ActiveX: localizando um controle ActiveX'
ms.date: 09/12/2018
f1_keywords:
- LocaleID
- AfxOleRegisterTypeLib
helpviewer_keywords:
- localization, ActiveX controls
- MFC ActiveX controls [MFC], localizing
- LocaleID ambient property [MFC]
- LOCALIZE sample [MFC]
ms.assetid: a44b839a-c652-4ec5-b824-04392708a5f9
ms.openlocfilehash: a85ec5cbed797b756afd93cd8423c58d138a0625
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615429"
---
# <a name="mfc-activex-controls-localizing-an-activex-control"></a>Controles MFC ActiveX: localizando um controle ActiveX

Este artigo discute os procedimentos para localizar interfaces de controle ActiveX.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Se você quiser adaptar um controle ActiveX a um mercado internacional, talvez queira localizar o controle. O Windows dá suporte a vários idiomas além do inglês padrão, incluindo alemão, francês e sueco. Isso pode apresentar problemas para o controle se sua interface estiver apenas em inglês.

Em geral, os controles ActiveX sempre devem basear sua localidade na Propriedade LocaleID de ambiente. Há três modos de fazer isso:

- Carregar recursos, sempre sob demanda, com base no valor atual da Propriedade LocaleID de ambiente. O exemplo de [Localizar](../overview/visual-cpp-samples.md) controles ActiveX do MFC usa essa estratégia.

- Carregue recursos quando o primeiro controle for instância, com base na Propriedade LocaleID de ambiente, e use esses recursos para todas as outras instâncias. Este artigo demonstra essa estratégia.

    > [!NOTE]
    >  Isso não funcionará corretamente em alguns casos, se as instâncias futuras tiverem localidades diferentes.

- Use a `OnAmbientChanged` função de notificação para carregar dinamicamente os recursos apropriados para a localidade do contêiner.

    > [!NOTE]
    >  Isso funcionará para o controle, mas a DLL de tempo de execução não atualizará dinamicamente seus próprios recursos quando a propriedade de LocaleID de ambiente for alterada. Além disso, as DLLs de tempo de execução para controles ActiveX usam a localidade do thread para determinar a localidade de seus recursos.

O restante deste artigo descreve duas estratégias de localização. A primeira estratégia [localiza a interface de programação do controle](#_core_localizing_your_control.92.s_programmability_interface) (nomes de propriedades, métodos e eventos). A segunda estratégia [localiza a interface do usuário do controle](#_core_localizing_the_control.92.s_user_interface), usando a Propriedade LocaleID do ambiente do contêiner. Para ver uma demonstração da localização de controle, consulte o exemplo de [Localizar](../overview/visual-cpp-samples.md)controles ActiveX do MFC.

## <a name="localizing-the-controls-programmability-interface"></a><a name="_core_localizing_your_control.92.s_programmability_interface"></a>Localizando a interface de programação do controle

Ao localizar a interface de programação do controle (a interface usada pelos programadores que escrevem aplicativos que usam seu controle), você deve criar uma versão modificada do controle. Arquivo IDL (um script para criar a biblioteca de tipos de controle) para cada idioma para o qual você pretende dar suporte. Esse é o único lugar que você precisa para localizar os nomes de propriedade de controle.

Quando você desenvolve um controle localizado, inclua a ID de localidade como um atributo no nível da biblioteca de tipos. Por exemplo, se você quiser fornecer uma biblioteca de tipos com nomes de propriedade localizadas em francês, faça uma cópia do seu exemplo. Arquivo IDL e chame-o de SAMPLEFR. Inseri. Adicione um atributo de ID de localidade ao arquivo (a ID de localidade para francês é 0x040c), semelhante ao seguinte:

[!code-cpp[NVC_MFC_AxLoc#1](codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_1.idl)]

Altere os nomes de propriedade em SAMPLEFR. IDL para seus equivalentes em francês e, em seguida, use MKTYPLIB. EXE para produzir a biblioteca de tipos em francês, SAMPLEFR. TLB.

Para criar várias bibliotecas de tipos localizadas, você pode adicionar qualquer localizado. Arquivos IDL para o projeto e eles serão criados automaticamente.

#### <a name="to-add-an-idl-file-to-your-activex-control-project"></a>Para adicionar um. Arquivo IDL para seu projeto de controle ActiveX

1. Com seu projeto de controle aberto, no menu **projeto** , clique em **Adicionar item existente**.

   A caixa de diálogo **Adicionar item existente** é exibida.

1. Se necessário, selecione a unidade e o diretório a serem exibidos.

1. Na caixa **arquivos do tipo** , selecione **todos os arquivos ( \* . \* )**.

1. Na caixa de listagem arquivo, clique duas vezes em. Arquivo IDL que você deseja inserir no projeto.

1. Clique em **abrir** quando tiver adicionado todos os necessários. Arquivos IDL.

Como os arquivos foram adicionados ao projeto, eles serão criados quando o restante do projeto for criado. As bibliotecas de tipos localizadas estão localizadas no diretório atual do projeto do controle ActiveX.

Dentro de seu código, os nomes de propriedade interna (geralmente em inglês) são sempre usados e nunca são localizados. Isso inclui o mapa de expedição de controle, a propriedade Exchange Functions e o código de troca de dados da página de propriedades.

Somente uma biblioteca de tipos (. O arquivo TLB) pode estar associado aos recursos da implementação do controle (. OCX). Normalmente, essa é a versão com os nomes padronizados (normalmente, em inglês). Para enviar uma versão localizada do seu controle, você precisa enviar o. OCX (que já foi associado ao padrão. Versão do TLB) e o. TLB para a localidade apropriada. Isso significa que apenas o. O OCX é necessário para versões em inglês, desde o correto. O TLB já foi associado a ele. Para outras localidades, a biblioteca de tipos localizada também deve ser enviada com o. OCX.

Para garantir que os clientes do seu controle possam encontrar a biblioteca de tipos localizada, registre sua localidade específica. Arquivo (s) TLB na seção TypeLib do registro do sistema do Windows. O terceiro parâmetro (normalmente opcional) da função [AfxOleRegisterTypeLib](reference/registering-ole-controls.md#afxoleregistertypelib) é fornecido para essa finalidade. O exemplo a seguir registra uma biblioteca de tipos em francês para um controle ActiveX:

[!code-cpp[NVC_MFC_AxLoc#2](codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_2.cpp)]

Quando o controle é registrado, a `AfxOleRegisterTypeLib` função procura automaticamente o especificado. Arquivo TLB no mesmo diretório que o controle e o registra no banco de dados de registro do Windows. Se o. O arquivo TLB não foi encontrado, a função não tem efeito.

## <a name="localizing-the-controls-user-interface"></a><a name="_core_localizing_the_control.92.s_user_interface"></a>Localizando a interface do usuário do controle

Para localizar a interface do usuário de um controle, coloque todos os recursos visíveis ao usuário do controle (como páginas de propriedades e mensagens de erro) em DLLs de recurso específicas do idioma. Em seguida, você pode usar a Propriedade LocaleID do ambiente do contêiner para selecionar a DLL apropriada para a localidade do usuário.

O exemplo de código a seguir demonstra uma abordagem para localizar e carregar a DLL de recurso para uma localidade específica. Essa função de membro, chamada `GetLocalizedResourceHandle` para este exemplo, pode ser uma função membro de sua classe de controle ActiveX:

[!code-cpp[NVC_MFC_AxLoc#3](codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_3.cpp)]

Observe que a ID do subidioma pode ser verificada em cada caso da instrução switch, para fornecer localização mais especializada. Para ver uma demonstração dessa função, consulte a `GetResourceHandle` função no exemplo de controles do ActiveX [LOCALIZE](../overview/visual-cpp-samples.md)do MFC.

Quando o controle se carrega pela primeira vez em um contêiner, ele pode chamar [COleControl:: AmbientLocaleID](reference/colecontrol-class.md#ambientlocaleid) para recuperar a ID de localidade. O controle pode passar o valor de ID de localidade retornado para a `GetLocalizedResourceHandle` função, que carrega a biblioteca de recursos apropriada. O controle deve passar o identificador resultante, se houver, para [AfxSetResourceHandle](reference/application-information-and-management.md#afxsetresourcehandle):

[!code-cpp[NVC_MFC_AxLoc#4](codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_4.cpp)]

Coloque o exemplo de código acima em uma função membro do controle, como uma substituição de [COleControl:: OnSetClientSite](reference/colecontrol-class.md#onsetclientsite). Além disso, *m_hResDLL* deve ser uma variável de membro da classe Control.

Você pode usar uma lógica semelhante para localizar a página de propriedades de um controle. Para localizar a página de propriedades, adicione um código semelhante ao exemplo a seguir ao arquivo de implementação da sua página de Propriedades (em uma substituição de [COlePropertyPage:: OnSetPageSite](reference/colepropertypage-class.md#onsetpagesite)):

[!code-cpp[NVC_MFC_AxLoc#5](codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_5.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
