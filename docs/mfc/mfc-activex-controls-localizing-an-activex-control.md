---
title: 'Controles ActiveX MFC: Localizando um controle ActiveX | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- LocaleID
- AfxOleRegisterTypeLib
dev_langs: C++
helpviewer_keywords:
- localization, ActiveX controls
- MFC ActiveX controls [MFC], localizing
- LocaleID ambient property [MFC]
- LOCALIZE sample [MFC]
ms.assetid: a44b839a-c652-4ec5-b824-04392708a5f9
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 44b3a608379d2fe8f5a87c5f58bfc71936e241be
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mfc-activex-controls-localizing-an-activex-control"></a>Controles MFC ActiveX: localizando um controle ActiveX
Este artigo descreve procedimentos para localização de interfaces de controle ActiveX.  
  
 Se você quiser adaptar um controle ActiveX para um mercado internacional, talvez queira localizar o controle. Windows dá suporte a vários idiomas além do inglês, incluindo alemão, francês e sueco padrão. Isso pode apresentar problemas para o controle se sua interface está apenas em inglês.  
  
 Em geral, controles ActiveX sempre devem basear sua localidade na propriedade de identificação de localidade de ambiente. Há três maneiras de fazer isso:  
  
-   Carregue os recursos sempre sob demanda, com base no valor da propriedade ambiente LocaleID atual. Exemplo de controles do ActiveX MFC [LOCALIZE](../visual-cpp-samples.md) usa essa estratégia.  
  
-   Carregar recursos quando o primeiro controle é instanciado, com base na propriedade de ambiente LocaleID e usar esses recursos para todas as outras instâncias. Este artigo demonstra essa estratégia.  
  
    > [!NOTE]
    >  Isso não funcionará corretamente em alguns casos, se instâncias futuras têm diferentes localidades.  
  
-   Use o **OnAmbientChanged** função de notificação para carregar dinamicamente os recursos apropriados para a localidade do contêiner.  
  
    > [!NOTE]
    >  Isso funcionará para o controle, mas o DLL de tempo de execução não atualizará dinamicamente seus próprios recursos quando a propriedade de ambiente LocaleID é alterado. Além disso, as DLLs de tempo de execução para controles ActiveX usam a localidade do thread para determinar a localidade para seus recursos.  
  
 O restante deste artigo descreve duas estratégias de localizações. A primeira estratégia [localiza a interface de programação do controle](#_core_localizing_your_control.92.s_programmability_interface) (nomes de propriedades, métodos e eventos). A segunda estratégia [localiza a interface do usuário do controle](#_core_localizing_the_control.92.s_user_interface), usando a propriedade identificador de ambiente do contêiner. Para ver uma demonstração de localização de controle, consulte o exemplo de controles ActiveX MFC [LOCALIZE](../visual-cpp-samples.md).  
  
##  <a name="_core_localizing_your_control.92.s_programmability_interface"></a>Localizando a Interface de programação do controle  
 Ao localizar a interface de programação do controle (a interface usada por programadores que criam aplicativos que usam o controle), você deve criar uma versão modificada do controle. IDL arquivo (um script para criar a biblioteca de tipos de controle) para cada idioma que você pretende dar suporte. Este é o único local em que você precisa localizar os nomes de propriedade do controle.  
  
 Quando você desenvolve um controle localizado, inclua a ID de localidade como um atributo no nível da biblioteca de tipo. Por exemplo, se você quiser fornecer uma biblioteca de tipos com nomes de propriedade localizada francês, faça uma cópia de seu exemplo. IDL do arquivo e chame-SAMPLEFR. IDL. Adicionar um atributo de ID de localidade para o arquivo (a ID de localidade para francês é 0x040c), semelhante à seguinte:  
  
 [!code-cpp[NVC_MFC_AxLoc#1](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_1.idl)]  
  
 Altere os nomes de propriedade no SAMPLEFR. IDL para seus equivalentes em francês e, em seguida, use MKTYPLIB. EXE para produzir o francês tipo de biblioteca, SAMPLEFR. TLB.  
  
 Para criar várias bibliotecas de tipo localizado, você pode adicionar qualquer localizado. Arquivos IDL para o projeto e eles serão criados automaticamente.  
  
#### <a name="to-add-an-idl-file-to-your-activex-control-project"></a>Para adicionar um. Arquivo IDL para o projeto de controle ActiveX  
  
1.  Com o seu projeto de controle aberto, no **projeto** menu, clique em **Add Existing Item**.  
  
     O **Add Existing Item** caixa de diálogo é exibida.  
  
2.  Se necessário, selecione a unidade e diretório para exibir.  
  
3.  No **arquivos do tipo** selecione **todos os arquivos (\*.\*)** .  
  
4.  Na caixa de listagem de arquivos, clique duas vezes o. Arquivo IDL que deseja inserir no projeto.  
  
5.  Clique em **abrir** quando você tiver adicionado todos os. Arquivos IDL.  
  
 Porque os arquivos foram adicionados ao projeto, eles serão criados quando o restante do projeto é compilado. As bibliotecas de tipo localizado estão localizadas no diretório do projeto atual do controle ActiveX.  
  
 Dentro de seu código, os nomes de propriedade interna (normalmente em inglês) são sempre usados e nunca são localizados. Isso inclui o mapa de expedição de controle, as funções do exchange de propriedade e o código de troca de dados de página de propriedade.  
  
 Biblioteca de apenas um tipo (. Arquivos TLB) podem ser associados a recursos da implementação do controle (. Arquivo OCX). Isso geralmente é a versão com o padronizado (normalmente, em inglês) nomes. Para enviar uma versão localizada do seu controle você precisa enviar o. OCX (que já foi associada para o padrão. Versão TLB) e o. TLB para a localidade apropriada. Isso significa que somente o. OCX é necessária para versões em inglês, desde o correto. TLB já foi associada a ele. Para outras localidades, a biblioteca de tipo localizado também deve ser enviada com o. OCX.  
  
 Para garantir que os clientes do seu controle podem encontrar a biblioteca de tipo localizado, registre seu específicas da localidade. Arquivos TLB na seção TypeLib do registro do sistema do Windows. O terceiro parâmetro (normalmente opcional) do [AfxOleRegisterTypeLib](../mfc/reference/registering-ole-controls.md#afxoleregistertypelib) função é fornecida para essa finalidade. O exemplo a seguir registra uma biblioteca de tipos francês para um controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxLoc#2](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_2.cpp)]  
  
 Quando o controle é registrado, o `AfxOleRegisterTypeLib` função procura automaticamente especificado. Arquivos TLB no mesmo diretório que o controle e o registra no banco de dados de registro do Windows. Se o. Arquivos TLB não for encontrado, a função não tem nenhum efeito.  
  
##  <a name="_core_localizing_the_control.92.s_user_interface"></a>Localizando a Interface do usuário do controle  
 Para localizar a interface do usuário do controle, coloque todos os recursos de usuário visível do controle (como páginas de propriedade e mensagens de erro) em DLLs de recurso específico do idioma. Em seguida, você pode usar propriedade LocaleID de ambiente do contêiner para selecionar a DLL apropriada para a localidade do usuário.  
  
 O exemplo de código a seguir demonstra uma abordagem para localizar e carregar a DLL de recurso para uma localidade específica. Essa função de membro, chamada `GetLocalizedResourceHandle` para este exemplo, pode ser uma função de membro da classe do controle ActiveX:  
  
 [!code-cpp[NVC_MFC_AxLoc#3](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_3.cpp)]  
  
 Observe que a identificação de subidioma pôde ser verificada em cada caso da instrução switch, para fornecer mais especializadas de localização. Para ver uma demonstração dessa função, consulte o `GetResourceHandle` função do ActiveX MFC controla exemplo [LOCALIZE](../visual-cpp-samples.md).  
  
 Quando o controle carrega-se primeiro em um contêiner, ele pode chamar [COleControl::AmbientLocaleID](../mfc/reference/colecontrol-class.md#ambientlocaleid) para recuperar a ID de localidade. O controle pode passar o valor de ID de localidade retornado para o `GetLocalizedResourceHandle` função, que carrega a biblioteca de recursos apropriado. O controle deve passar o identificador resultante, se houver, para [AfxSetResourceHandle](../mfc/reference/application-information-and-management.md#afxsetresourcehandle):  
  
 [!code-cpp[NVC_MFC_AxLoc#4](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_4.cpp)]  
  
 Coloque o código de exemplo acima em uma função de membro de controle, como uma substituição de [COleControl::OnSetClientSite](../mfc/reference/colecontrol-class.md#onsetclientsite). Além disso, `m_hResDLL` deve ser uma variável de membro da classe de controle.  
  
 Você pode usar lógica semelhante para localizar a página de propriedades do controle. Para localizar a página de propriedades, adicione código semelhante ao exemplo a seguir ao arquivo de implementação da sua página de propriedade (em uma substituição de [COlePropertyPage::OnSetPageSite](../mfc/reference/colepropertypage-class.md#onsetpagesite)):  
  
 [!code-cpp[NVC_MFC_AxLoc#5](../mfc/codesnippet/cpp/mfc-activex-controls-localizing-an-activex-control_5.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

