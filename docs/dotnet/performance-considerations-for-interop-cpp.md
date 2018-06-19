---
title: Considerações sobre desempenho de interoperabilidade (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- /clr compiler option [C++], interop performance considerations
- platform invoke [C++], interoperability
- interop [C++], performance consideraitons
- mixed assemblies [C++], performance considerations
- interoperability [C++], performance considerations
ms.assetid: bb9a282e-c3f8-40eb-a2fa-45d80d578932
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9223c52e4ef831a9a1ff657db1a0d7859dd6ce6c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33164044"
---
# <a name="performance-considerations-for-interop-c"></a>Considerações sobre desempenho para interop (C++)
Este tópico fornece diretrizes para reduzir o efeito de transições de interoperabilidade gerenciado/não gerenciado no desempenho de tempo de execução.  
  
 Visual C++ suporta os mesmos mecanismos de interoperabilidade que outras linguagens .NET, como Visual Basic e c# (P/Invoke), mas ele também fornece suporte de interoperabilidade que é específico para o Visual C++ (interoperabilidade C++). Para aplicativos críticos de desempenho, é importante entender as implicações de desempenho de cada técnica de interoperabilidade.  
  
 Independentemente da interoperabilidade técnica usada, sequências de transição especial, chamadas conversões, são necessárias sempre que uma função gerenciada chama uma função e vice-versa não gerenciada. Essas conversões são inseridos automaticamente pelo compilador do Visual C++, mas é importante ter em mente que cumulativamente, essas transições podem ser caras em termos de desempenho.  
  
## <a name="reducing-transitions"></a>Reduzir transições  
 É uma maneira de evitar ou reduzir o custo de conversões de interoperabilidade refatorar interfaces envolvidas minimizar as transições gerenciado/não gerenciado. Melhorias de desempenho podem ser feitas ao direcionar interfaces verborrágicas, que são aqueles que envolvidos chamadas frequentes entre o limite gerenciado/não gerenciado. Uma função gerenciada que chama uma função não gerenciada em um loop estreito, por exemplo, é uma boa candidata para refatoração. Se o próprio loop é movido para o lado de não gerenciado, ou se uma alternativa gerenciada para a chamada não gerenciada é criada (talvez ser dados do enfileiramento de mensagens no lado gerenciado e empacotamento para a API não gerenciada de uma vez após o loop), o número de transições pode ser reduzido de sinal ificantly.  
  
## <a name="pinvoke-vs-c-interop"></a>P/Invoke vs. Interoperabilidade C++  
 Para as linguagens .NET, como Visual Basic e c#, o método indicado para interagir com componentes nativo é P/Invoke. Como P/Invoke é suportado pelo .NET Framework, Visual C++ dá suporte a ele também, mas o Visual C++ também fornece seu próprio suporte de interoperabilidade, que é chamado de interoperabilidade C++. Interoperabilidade C++ é preferível P/Invoke porque P/Invoke não é do tipo seguro. Como resultado, principalmente são relatados erros em tempo de execução, mas o C++ Interop também tem vantagens de desempenho sobre P/Invoke.  
  
 Ambas as técnicas exigem várias coisas a serem sempre que uma função gerenciada chama uma função não gerenciada:  
  
-   Os argumentos de chamada de função são empacotados do CLR para tipos nativos.  
  
-   Uma conversão para gerenciado é executada.  
  
-   A função não gerenciada é chamada (usando as versões nativas de argumentos).  
  
-   Uma conversão de não gerenciado para gerenciado é executado.  
  
-   O tipo de retorno e qualquer "out" ou "em, out" argumentos são empacotados de nativo para tipos CLR.  
  
 As conversões gerenciado/não gerenciado são necessárias para interoperabilidade funcionar, mas o marshaling de dados que é necessário depende dos tipos de dados envolvidos, a assinatura de função e como os dados serão usados.  
  
 O empacotamento de dados executada pelo interoperabilidade C++ é a forma mais simples possível: os parâmetros são simplesmente copiados entre o limite gerenciado/não gerenciado de maneira bit a bit; Nenhuma transformação é executada em todos os. Para P/Invoke, isso é verdadeiro somente se todos os parâmetros são simples, tipos blittable. Caso contrário, o P/Invoke executa etapas muito eficiente para converter cada parâmetro gerenciado em um tipo nativo apropriado, e vice-versa, se os argumentos são marcados como "out" ou "em, out".  
  
 Em outras palavras, o C++ Interop usa o método mais rápido possível de marshaling de dados, enquanto P/Invoke usa o método mais eficiente. Isso significa que o C++ Interop (de uma maneira comum de C++) fornece o melhor desempenho por padrão, e o programador é responsável para lidar com casos em que esse comportamento não é seguro ou apropriado.  
  
 Interoperabilidade C++, portanto, requer que o marshaling de dados deve ser fornecido explicitamente, mas a vantagem é que o programador está livre para decidir o que for apropriado, fornecido a natureza dos dados e como ele será usado. Além disso, embora o comportamento de marshaling de dados P/Invoke pode ser modificado em personalizado para um grau, interoperabilidade C++ permite empacotamento para ser personalizados em uma base por chamada de dados. Não é possível com P/Invoke.  
  
 Para obter mais informações sobre interoperabilidade C++, consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)