---
title: Considerações sobre desempenho para interop (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- /clr compiler option [C++], interop performance considerations
- platform invoke [C++], interoperability
- interop [C++], performance consideraitons
- mixed assemblies [C++], performance considerations
- interoperability [C++], performance considerations
ms.assetid: bb9a282e-c3f8-40eb-a2fa-45d80d578932
ms.openlocfilehash: c6b4456d9c75061c9a8c93f37f98b58f92adc899
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384745"
---
# <a name="performance-considerations-for-interop-c"></a>Considerações sobre desempenho para interop (C++)

Este tópico fornece diretrizes para reduzir o efeito de transições de interoperabilidade gerenciada/não gerenciados no desempenho de tempo de execução.

Visual C++ oferece suporte os mesmos mecanismos de interoperabilidade que outras linguagens .NET como Visual Basic e c# (P/Invoke), mas ele também fornece suporte de interoperabilidade que é específico para o Visual C++ (interop do C++). Para aplicativos críticos de desempenho, é importante entender as implicações de desempenho de cada técnica de interoperabilidade.

Independentemente da interoperabilidade técnica usada, sequências de transição especial, chamadas de conversões, são necessárias sempre que uma função gerenciada chama uma função e vice-versa não gerenciada. Essas conversões são inseridos automaticamente pelo compilador do Visual C++, mas é importante ter em mente que cumulativamente, essas transições podem ser caras em termos de desempenho.

## <a name="reducing-transitions"></a>Reduzindo as transições

Uma maneira de evitar ou reduzir o custo de conversões de interoperabilidade é refatorar as interfaces envolvidas minimizar as transições gerenciados/não gerenciados. Melhorias expressivas de desempenho podem ser feitas ao direcionar interfaces verborrágicas, que são aqueles que envolvia chamadas frequentes além do limite gerenciado /. Uma função que chama uma função não gerenciada em um loop estreito, por exemplo, é um bom candidato para refatoração. Se o próprio loop é movido para o lado não gerenciado, ou se uma alternativa gerenciada para a chamada não gerenciada será criada (talvez ser enfileirando dados no lado gerenciado e empacotá-las para a API não gerenciada ao mesmo tempo após o loop), o número de transições pode ser reduzido de entrada ificantly.

## <a name="pinvoke-vs-c-interop"></a>P/Invoke vs. Interoperabilidade C++

Para linguagens .NET, como Visual Basic e c#, o método prescrito para interoperar com componentes nativos é P/Invoke. Como P/Invoke é suportado pelo .NET Framework, Visual C++ oferece suporte a ele, bem, mas o Visual C++ também fornece seu próprio suporte de interoperabilidade, que é conhecido como Interop do C++. Interoperabilidade de C++ é preferível P/Invoke como P/Invoke não é fortemente tipada. Como resultado, os erros são relatados principalmente no tempo de execução, mas Interop do C++ também tem vantagens de desempenho sobre P/Invoke.

Ambas as técnicas exigem várias coisas que aconteça sempre que uma função gerenciada chama uma função não gerenciada:

- Os argumentos da chamada de função são empacotados do CLR para tipos nativos.

- Uma conversão para gerenciado é executada.

- A função não gerenciada é chamada (usando as versões nativas de argumentos).

- Uma conversão não gerenciado para gerenciado é executado.

- O tipo de retorno e qualquer "out" ou "no, out" argumentos são empacotados de nativo para tipos CLR.

As conversões de tipos gerenciados/não gerenciados são necessárias para a interoperabilidade funcione em todos os, mas o marshaling de dados que é necessário depende dos tipos de dados envolvidos, a assinatura de função e como os dados serão usados.

O marshaling de dados executada pelo Interop do C++ é a forma mais simples possível: os parâmetros são simplesmente copiados além do limite gerenciado/não gerenciados de forma bit a bit; Nenhuma transformação é executada em todos os. Para P/Invoke, isso é verdadeiro somente se todos os parâmetros são simples, os tipos blittable. Caso contrário, o P/Invoke executa etapas muito robustas para converter cada parâmetro gerenciado para um tipo nativo apropriado, e vice-versa, se os argumentos são marcados como "out" ou "no, out".

Em outras palavras, o Interop do C++ usa o método mais rápido possível de marshaling de dados, enquanto o P/Invoke usa o método mais robusto. Isso significa que o Interop do C++ (de uma forma típica para C++) proporciona um desempenho ideal, por padrão, e o programador é responsável para lidar com casos em que esse comportamento não é seguro ou apropriado.

Interoperabilidade de C++, portanto, requer que o marshaling de dados deve ser fornecido explicitamente, mas a vantagem é que o programador está livre para decidir o que é apropriado, dada a natureza dos dados e como ele deve ser usado. Além disso, embora o comportamento de marshaling de dados de P/Invoke pode ser modificado em personalizada de acordo com um grau, Interop do C++ permite que os dados de marshaling para ser personalizado em uma base por chamada. Isso não é possível com P/Invoke.

Para obter mais informações sobre a interoperabilidade de C++, consulte [usando Interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
